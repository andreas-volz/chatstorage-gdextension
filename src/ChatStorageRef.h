/*
 * ChatStorageRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef CHATSTORAGEREF_H_
#define CHATSTORAGEREF_H_

// project
#include "chatstorage/ChatStorage.h"
#include "ChatContextRef.h"
#include "ChatEntryRef.h"
#include "MediaRef.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class ChatStorageRef : public RefCounted
{
  GDCLASS(ChatStorageRef, RefCounted)

public:
  ChatStorageRef() = default;
  ~ChatStorageRef() override = default;

  void open_database(String db_path, String media_persistence_path);

  Array get_chat_entry_list();

  Ref<ChatContextRef> load_by_chat_entry(Ref<ChatEntryRef> chat_entry);

protected:
  static void _bind_methods();

private:
  std::unique_ptr<ChatStorage> mStorage;
};

#endif /* CHATSTORAGEREF_H_ */
