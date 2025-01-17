#pragma once
#include "UIView.h"
#include "../Objects/GizmoObject.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

namespace ed
{
	class PreviewUI : public UIView
	{
	public:
		PreviewUI(GUIManager* ui, ed::InterfaceManager* objects, const std::string& name = "", bool visible = true) :
			UIView(ui, objects, name, visible),
			m_pickMode(0),
			m_gizmo(objects->GetOwner()),
			m_fpsDelta(0.0f),
			m_fpsUpdateTime(0.0f),
			m_pos1(0,0,0), m_pos2(0,0,0),
			m_lastSize(-1, -1) {
			m_setupShortcuts();
			m_setupFXAA();
			m_setupBoundingBox();
			m_fpsLimit = m_elapsedTime = 0;
			m_hasFocus = false;
		}

		virtual void OnEvent(const ml::Event& e);
		virtual void Update(float delta);

		void Duplicate();
		void Pick(PipelineItem* item, bool add = false);
		inline bool IsPicked(PipelineItem* item) { return std::count(m_picks.begin(), m_picks.end(), item) > 0; }

	private:
		void m_setupShortcuts();
		void m_setupFXAA();
		void m_fxaaCreateQuad(DirectX::XMFLOAT2 size);
		void m_fxaaRenderQuad();

		void m_setupBoundingBox();
		void m_buildBoundingBox();
		void m_renderBoundingBox();

		ImVec2 m_mouseContact;
		DirectX::XMFLOAT3 m_tempTrans, m_tempScale, m_tempRota, 
			m_prevTrans, m_prevScale, m_prevRota;
		GizmoObject m_gizmo;

		DirectX::XMFLOAT3 m_pos1, m_pos2;

		ml::Timer m_fpsTimer;
		float m_fpsDelta;
		float m_fpsUpdateTime; // check if 0.5s passed then update the fps widget

		ml::RenderTexture m_rt;
		ml::ShaderResourceView m_rtView;
		DirectX::XMINT2 m_lastSize;
		bool m_hasFocus;

		// FXAA
		struct QuadVertex2D
		{
			DirectX::XMFLOAT4 Position;
			DirectX::XMFLOAT2 UV;
		};
		ml::VertexBuffer<QuadVertex2D> m_vbQuad;
		DirectX::XMFLOAT2 m_fxaaLastSize;
		struct cbData
		{
			float wndX;
			float wndY;
			float temp1, temp2;
		} m_cbData;
		ml::ConstantBuffer<cbData> m_fxaaCB;
		ml::VertexShader m_fxaaVS;
		ml::PixelShader m_fxaaPS;
		ml::VertexInputLayout m_fxaaInput;
		ml::ShaderResourceView m_fxaaContent;
		ml::RenderTexture m_fxaaRT;

		float m_elapsedTime;
		float m_fpsLimit;

		std::vector<PipelineItem*> m_picks;
		int m_pickMode; // 0 = position, 1 = scale, 2 = rotation

		// bounding box
		ml::VertexShader m_boxVS;
		ml::PixelShader m_boxPS;
		ml::VertexInputLayout m_boxInput;
		ml::VertexBuffer<QuadVertex2D> m_vbBoundingBox;
		__declspec(align(16))
			struct CBBoundingBox
		{
			DirectX::XMFLOAT4X4 matWVP;
			DirectX::XMFLOAT3 color;
		} m_cbBoxData;
		ml::ConstantBuffer<CBBoundingBox> m_cbBox;
	};
}