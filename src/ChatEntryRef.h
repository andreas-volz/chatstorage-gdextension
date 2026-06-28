/*
 * ChatEntryRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef CHATENTRYREF_H_
#define CHATENTRYREF_H_

// project
#include "chatstorage/ChatStorage.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

// system
#include <memory>

using namespace godot;

class ChatEntryRef : public RefCounted
{
  GDCLASS(ChatEntryRef, RefCounted)

public:
  ChatEntryRef() = default;
  ~ChatEntryRef() override = default;

  static Ref<ChatEntryRef> create_chat_entry_ref(const ChatEntry &chat_entry);

  String get_name();

  const ChatEntry &get();

protected:
  static void _bind_methods();

private:
  std::unique_ptr<ChatEntry> mChatEntry;
};

#endif /* CHATENTRYREF_H_ */
