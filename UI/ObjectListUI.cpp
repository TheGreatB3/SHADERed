#include "ObjectListUI.h"
#include "PropertyUI.h"
#include <imgui/imgui_internal.h>

#define IMAGE_CONTEXT_WIDTH 150

namespace ed
{
	void ObjectListUI::OnEvent(const ml::Event & e)
	{
	}
	void ObjectListUI::Update(float delta)
	{
		ImVec2 containerSize = ImVec2(ImGui::GetWindowContentRegionWidth(), abs(ImGui::GetWindowContentRegionMax().y - ImGui::GetWindowContentRegionMin().y));
		bool itemMenuOpened = false;
		std::vector<std::string> items = m_data->Objects.GetObjects();
		std::vector<PipelineItem*> passes = m_data->Pipeline.GetList();

		ImGui::BeginChild("##object_scroll_container", containerSize);

		if (items.size() == 0)
			ImGui::TextWrapped("Right click on this window or go to Create menu in the menu bar to create an item.");

		for (int i = 0; i < items.size(); i++) {
			ml::ShaderResourceView* srv = m_data->Objects.GetSRV(items[i]);

			float imgWH = 0.0f;
			if (m_data->Objects.IsRenderTexture(items[i])) {
				DirectX::XMINT2 rtSize = m_data->Objects.GetRenderTextureSize(items[i]);
				imgWH = (float)rtSize.y / rtSize.x;
			} else if (m_data->Objects.IsAudio(items[i])) {
				imgWH = 2.0f / 512.0f;
			} else {
				ml::Image* img = m_data->Objects.GetImage(items[i]);
				DirectX::Image imgData = img->GetImage()->GetImages()[0];
				imgWH = (float)imgData.height / imgData.width;
			}

			size_t lastSlash = items[i].find_last_of("/\\");
			std::string itemText = items[i];

			if (lastSlash != std::string::npos)
				itemText = itemText.substr(lastSlash + 1);

			if (m_data->Objects.IsLoading(items[i]))
				ImGui::PushStyleColor(ImGuiCol_Text, IMGUI_WARNING_COLOR);

			ImGui::Selectable(itemText.c_str());

			if (m_data->Objects.IsLoading(items[i]))
				ImGui::PopStyleColor();

			if (ImGui::BeginPopupContextItem(std::string("##context" + items[i]).c_str())) {
				itemMenuOpened = true;
				ImGui::Text("Preview");
				ImGui::Image(srv->GetView(), ImVec2(IMAGE_CONTEXT_WIDTH, ((float)imgWH)* IMAGE_CONTEXT_WIDTH));

				ImGui::Separator();


				if (ImGui::BeginMenu("Bind")) {
					for (int j = 0; j < passes.size(); j++) {
						int boundID = m_data->Objects.IsBound(items[i], passes[j]);
						size_t boundItemCount = m_data->Objects.GetBindList(passes[j]).size();
						bool isBound = boundID != -1;
						if (ImGui::MenuItem(passes[j]->Name, ("(" + std::to_string(boundID == -1 ? boundItemCount : boundID) + ")").c_str(), isBound)) {
							if (!isBound)
								m_data->Objects.Bind(items[i], passes[j]);
							else
								m_data->Objects.Unbind(items[i], passes[j]);
						}
					}
					ImGui::EndMenu();
				}

				if (m_data->Objects.IsRenderTexture(items[i])) {
					if (ImGui::Selectable("Properties")) {
						((ed::PropertyUI*)m_ui->Get(ViewID::Properties))->Open(items[i], m_data->Objects.GetRenderTexture(items[i]));
					}
				}

				if (m_data->Objects.IsAudio(items[i])) {
					bool isMuted = m_data->Objects.IsAudioMuted(items[i]);
					if (ImGui::MenuItem("Mute", (const char*)0, &isMuted)) {
						if (isMuted)
							m_data->Objects.Mute(items[i]);
						else
							m_data->Objects.Unmute(items[i]);
					}
				}

				if (ImGui::Selectable("Delete")) {
					if (m_data->Objects.IsRenderTexture(items[i])) {
						auto& passes = m_data->Pipeline.GetList();
						for (int j = 0; j < passes.size(); j++) {
							pipe::ShaderPass* sData = (pipe::ShaderPass*)passes[j]->Data;

							for (int k = 0; k < D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT; k++) {
								if (items[i] == sData->RenderTexture[k]) {
									// TODO: maybe implement better logic for what to replace the deleted RT with
									bool alreadyUsesWindow = false;
									for (int l = 0; l < D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT; l++)
										if (strcmp(sData->RenderTexture[l], "Window") == 0) {
											alreadyUsesWindow = true;
											break;
										}

									if (!alreadyUsesWindow)
										strcpy(sData->RenderTexture[k], "Window");
									else if (k != 0) {
										for (int l = j; l < D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT; l++)
											sData->RenderTexture[l][0] = 0;
									}
									else {
										for (int l = 0; l < D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT; l++)
											sData->RenderTexture[l][0] = 0;
										strcpy(sData->RenderTexture[0], "Window");
									}
								}
							}
						}
					}

					((PropertyUI*)m_ui->Get(ViewID::Properties))->Open(nullptr);
					m_data->Objects.Remove(items[i]);
				}

				ImGui::EndPopup();
			}
		}

		ImGui::EndChild();

		if (!itemMenuOpened && ImGui::BeginPopupContextItem("##context_main_objects")) {
			if (ImGui::Selectable("Create Texture")) { m_ui->CreateNewTexture(); }
			if (ImGui::Selectable("Create Cubemap")) { m_ui->CreateNewCubemap(); }
			if (ImGui::Selectable("Create Render Texture")) { m_ui->CreateNewRenderTexture(); }
			if (ImGui::Selectable("Create Audio")) { m_ui->CreateNewAudio(); }

			ImGui::EndPopup();
		}
	}
}