#pragma once
#include <MoonLight/Base/Window.h>
#include "Objects/KeyboardShortcuts.h"
#include <map>

namespace ed
{
	class InterfaceManager;
	class CreateItemUI;
	class UIView;
	class Settings;

	enum class ViewID
	{
		Pinned,
		Preview,
		Code,
		Output,
		Objects,
		Pipeline,
		Properties,
		Options
	};

	class GUIManager
	{
	public:
		GUIManager(ed::InterfaceManager* objects, ml::Window* wnd);
		~GUIManager();

		void OnEvent(const ml::Event& e);
		void Update(float delta);
		void Render();

		UIView* Get(ViewID view);

		void SaveSettings();
		void LoadSettings();

		void CreateNewShaderPass();
		void CreateNewTexture();
		void CreateNewCubemap();
		void CreateNewAudio();
		inline void CreateNewRenderTexture() { m_isCreateRTOpened = true; }

	private:
		void m_setupShortcuts();

		void m_imguiHandleEvent(const ml::Event& e);

		void m_renderOptions();
		bool m_optionsOpened;
		int m_optGroup;
		UIView* m_options;

		std::string m_cachedFont;
		int m_cachedFontSize;
		bool m_cachedCustomFont;
		bool m_fontNeedsUpdate;
		float m_cacheUIScale;

		bool m_isCreateItemPopupOpened, m_isCreateRTOpened, m_isNewProjectPopupOpened, m_isAboutOpen;

		Settings* m_settingsBkp;
		std::map<std::string, KeyboardShortcuts::Shortcut> m_shortcutsBkp;

		bool m_savePreviewPopupOpened;
		std::string m_previewSavePath;
		DirectX::XMINT2 m_previewSaveSize;

		bool m_performanceMode, m_perfModeFake;

		std::string m_selectedTemplate;
		std::vector<std::string> m_templates;
		void m_loadTemplateList();

		std::vector<UIView*> m_views;
		CreateItemUI* m_createUI;

		ml::Window* m_wnd;
		InterfaceManager* m_data;

		bool m_saveAsProject();
	};
}