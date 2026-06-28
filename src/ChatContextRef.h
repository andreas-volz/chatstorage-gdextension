/*
 * ChatContextViewRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef CHATCONTEXTVIEWREF_H_
#define CHATCONTEXTVIEWREF_H_

// Godot wrapper public API
#include "ChatRef.h"
#include "UserRef.h"
#include "MediaRef.h"
#include "ContextHandle.h"

// project public API
#include "chatstorage/ChatContext.h"
#include "chatstorage/ChatStorage.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

// system
#include <memory>

using namespace godot;

class ChatContextRef : public RefCounted
{
  GDCLASS(ChatContextRef, RefCounted)

public:
  ChatContextRef() = default;
  ~ChatContextRef() override = default;

  static Ref<ChatContextRef> create_chat_context_ref(std::unique_ptr<ChatContext> &&chat_context, ChatStorage *chat_storage);

  Ref<ChatRef> get_chat();

  Array get_user_list();

  Array get_message_list();

  Array get_media_list();


protected:
  static void _bind_methods();

private:
  std::unique_ptr<ChatContext> mChatContext;
  ChatStorage *mChatStorage = nullptr;

  ContextHandle mContextHandle;
};

#endif /* CHATCONTEXTVIEWREF_H_ */
