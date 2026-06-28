/*
 * MessageViewRef.cpp
 *
 *      Author: Andreas Volz
 */

#include "MessageRef.h"

Ref<MessageRef> MessageRef::create_message_ref(ContextHandle context_handle, const Message &message)
{
  Ref<MessageRef> ref;
  ref.instantiate();
  ref->mContextHandle = context_handle;
  ref->mMessage = std::make_unique<Message>(message);
  return ref;
}

void MessageRef::_bind_methods()
{
  godot::ClassDB::bind_method(D_METHOD("get_sender"), &MessageRef::get_sender);
  godot::ClassDB::bind_method(D_METHOD("get_timestamp"), &MessageRef::get_timestamp);
  godot::ClassDB::bind_method(D_METHOD("get_text"), &MessageRef::get_text);
  godot::ClassDB::bind_method(D_METHOD("get_media"), &MessageRef::get_media);
}

Ref<MediaRef> MessageRef::get_media() const
{
  int64_t runtime_id = mMessage->getMediaRuntimeId();

  if (runtime_id != Media::DB_NO_ID)
  {
    const Media &media = mContextHandle.context->getMediaByMediaRuntimeId(runtime_id);
    return MediaRef::create_media_ref(mContextHandle, media);
  }

  return nullptr;
}

Ref<UserRef> MessageRef::get_sender() const
{
  int64_t runtime_id = mMessage->getSenderRuntimeId();

  if (runtime_id != User::DB_NO_ID)
  {
    const User &user = mContextHandle.context->getUserBySenderRuntimeId(runtime_id);
    return UserRef::create_user_ref(mContextHandle, user);
  }

  return nullptr;
}

int64_t MessageRef::get_timestamp() const
{
  return mMessage->getTimestamp();
}

String MessageRef::get_text() const
{
  return String::utf8(mMessage->getText().c_str());
}



