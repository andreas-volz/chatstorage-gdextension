/*
 * ChatViewRef.cpp
 *
 *      Author: Andreas Volz
 */

#include "ChatRef.h"

Ref<ChatRef> ChatRef::create_object_ref(const Chat &chat)
{
  Ref<ChatRef> ref;
  ref.instantiate();
  ref->mChat = std::make_unique<Chat>(chat);
  return ref;
}

void ChatRef::_bind_methods()
{
  godot::ClassDB::bind_method(D_METHOD("get_name"), &ChatRef::get_name);
  godot::ClassDB::bind_method(D_METHOD("get_source"), &ChatRef::get_source);

  BIND_ENUM_CONSTANT(ChatSourceGodot::CHAT_SOURCE_FORMAT_A);
  BIND_ENUM_CONSTANT(ChatSourceGodot::CHAT_SOURCE_FORMAT_B);
}

String ChatRef::get_name() const
{
  return String::utf8(mChat->getName().c_str());
}

int ChatRef::get_source() const
{
  return static_cast<int>(mChat->getSource());
}
