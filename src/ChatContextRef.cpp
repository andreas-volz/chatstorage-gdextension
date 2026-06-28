/*
 * ChatContextViewRef.cpp
 *
 *      Author: Andreas Volz
 */

#include "ChatContextRef.h"
#include "MediaRef.h"
#include "MessageRef.h"
#include "UserRef.h"

void ChatContextRef::_bind_methods()
{
  godot::ClassDB::bind_method(D_METHOD("get_chat"), &ChatContextRef::get_chat);
  godot::ClassDB::bind_method(D_METHOD("get_user_list"), &ChatContextRef::get_user_list);
  godot::ClassDB::bind_method(D_METHOD("get_message_list"), &ChatContextRef::get_message_list);
  godot::ClassDB::bind_method(D_METHOD("get_media_list"), &ChatContextRef::get_media_list);
}

Ref<ChatContextRef> ChatContextRef::create_chat_context_ref(std::unique_ptr<ChatContext> &&chat_context, ChatStorage *chat_storage)
{
  Ref<ChatContextRef> ref;
  ref.instantiate();
  ref->mChatStorage = chat_storage;
  ref->mChatContext = std::move(chat_context);

  // put both pointers into the handle that the complete object tree could access it but ownership isn't changed!
  ref->mContextHandle = { chat_storage, ref->mChatContext.get() };

  return ref;
}

Ref<ChatRef> ChatContextRef::get_chat()
{
  return ChatRef::create_object_ref(*mChatContext->getChat());
}

Array ChatContextRef::get_user_list()
{
  Array result;

  std::vector<User> user_list = mChatContext->getUserList();

  for (auto uv_it = user_list.begin(); uv_it != user_list.end(); uv_it++)
  {
    User &user = *uv_it;
    result.append(UserRef::create_user_ref(mContextHandle, user));
  }

  return result;
}

Array ChatContextRef::get_message_list()
{
  Array result;

  std::vector<Message> message_list = mChatContext->getMessageList();

  for (auto mv_it = message_list.begin(); mv_it != message_list.end(); mv_it++)
  {
    Message &message = *mv_it;
    result.append(MessageRef::create_message_ref(mContextHandle, message));
  }

  return result;
}

Array ChatContextRef::get_media_list()
{
  Array result;

  std::vector<Media> media_list = mChatContext->getMediaList();

  for (auto mv_it = media_list.begin(); mv_it != media_list.end(); mv_it++)
  {
    Media &media = *mv_it;
    result.append(MediaRef::create_media_ref(mContextHandle, media));
  }

  return result;
}



