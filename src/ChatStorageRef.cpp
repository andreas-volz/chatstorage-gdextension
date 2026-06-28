/*
 * ChatStorageRef.cpp
 *
 *      Author: Andreas Volz
 */

// project
#include "ChatStorageRef.h"
#include "ChatRef.h"
#include "ChatEntryRef.h"

// system
#include <filesystem>

void ChatStorageRef::_bind_methods()
{
  godot::ClassDB::bind_method(D_METHOD("open_database", "db_path", "media_persistence_path"), &ChatStorageRef::open_database);
  godot::ClassDB::bind_method(D_METHOD("load_by_chat_entry", "chat_entry"), &ChatStorageRef::load_by_chat_entry);
  godot::ClassDB::bind_method(D_METHOD("get_chat_entry_list"), &ChatStorageRef::get_chat_entry_list);
}

void ChatStorageRef::open_database(String db_path, String media_persistence_path)
{
  mStorage = std::make_unique<ChatStorage>(std::filesystem::path(db_path.utf8().get_data()), std::filesystem::path(media_persistence_path.utf8().get_data()));
}

Array ChatStorageRef::get_chat_entry_list()
{
  Array result;

  std::vector<ChatEntry> chat_entry_list =  mStorage->getChatEntryList();

  for (auto &chat_entry : chat_entry_list)
  {
    result.append(ChatEntryRef::create_chat_entry_ref(chat_entry));
  }

  return result;
}

Ref<ChatContextRef> ChatStorageRef::load_by_chat_entry(Ref<ChatEntryRef> chat_entry)
{
  std::unique_ptr<ChatContext> chat_context = mStorage->loadByChatEntry(chat_entry->get());
  return ChatContextRef::create_chat_context_ref(std::move(chat_context), mStorage.get());
}



