#pragma once
#include <string>
#include "../GUIManager.h"
#include "ShaderVariable.h"
#include "MessageStack.h"
#include <pugixml/src/pugixml.hpp>
#include <MoonLight/Model/OBJModel.h>

namespace ed
{
	class PipelineManager;
	class RenderEngine;
	class ObjectManager;

	class ProjectParser
	{
	public:
		ProjectParser(PipelineManager* pipeline, ObjectManager* objects, RenderEngine* renderer, MessageStack* msgs, GUIManager* gui);
		~ProjectParser();

		void Open(const std::string& file);
		void OpenTemplate();
		inline void SetTemplate(const std::string& str) { m_template = str; }

		void Save();
		void SaveAs(const std::string& file, bool copyFiles = false);

		std::string LoadProjectFile(const std::string& file);
		char* LoadProjectFile(const std::string& file, size_t& len);
		ml::OBJModel* LoadModel(const std::string& file);

		void SaveProjectFile(const std::string& file, const std::string& data);

		std::string GetRelativePath(const std::string& to);
		std::string GetProjectPath(const std::string& projectFile);
		bool FileExists(const std::string& file);

		void ResetProjectDirectory();
		inline void SetProjectDirectory(const std::string& path) { m_projectPath = path; }
		inline std::string GetProjectDirectory() { return m_projectPath; }

		inline std::string GetOpenedFile() { return m_file; }

	private:
		void m_parseVariableValue(pugi::xml_node& node, ShaderVariable* var);
		void m_exportVariableValue(pugi::xml_node& node, ShaderVariable* vars);
		void m_exportShaderVariables(pugi::xml_node& node, std::vector<ShaderVariable*>& vars);
		D3D11_BLEND m_toBlend(const char* str);
		D3D11_BLEND_OP m_toBlendOp(const char* str);
		D3D11_COMPARISON_FUNC m_toComparisonFunc(const char* str);
		D3D11_STENCIL_OP m_toStencilOp(const char* str);
		D3D11_CULL_MODE m_toCullMode(const char* str);

		GUIManager* m_ui;
		PipelineManager* m_pipe;
		ObjectManager* m_objects;
		RenderEngine* m_renderer;
		MessageStack* m_msgs;
		std::string m_file;
		std::string m_projectPath;
		std::string m_template;

		std::vector<std::pair<std::string, ml::OBJModel*>> m_models;
	};
}