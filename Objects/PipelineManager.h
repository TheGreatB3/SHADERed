#pragma once
#include <vector>
#include "../Options.h"
#include "PipelineItem.h"

namespace ed
{
	class ProjectParser;

	class PipelineManager
	{
	public:

		PipelineManager(ml::Window* wnd, ProjectParser* project);
		~PipelineManager();

		void Clear();

		bool AddItem(const char* owner, const char* name, PipelineItem::ItemType type, void* data);
		bool AddPass(const char* name, ed::pipe::ShaderPass* data);
		void Remove(const char* name);
		bool Has(const char* name);
		PipelineItem* Get(const char* name);
		char* GetItemOwner(const char* name);
		inline std::vector<PipelineItem*>& GetList() { return m_items; }

		void New(bool openTemplate = true);

		inline ml::Window* GetOwner() { return m_wnd; }

	private:
		ml::Window* m_wnd;
		ProjectParser* m_project;
		std::vector<PipelineItem*> m_items;
	};
}