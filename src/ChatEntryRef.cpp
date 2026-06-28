/*
 * ChatEntryRef.cpp
 *
 *      Author: Andreas Volz
 */

#include "ChatEntryRef.h"

Ref<ChatEntryRef> ChatEntryRef::create_chat_entry_ref(const ChatEntry &chat_entry)
{
  Ref<ChatEntryRef> ref;
  ref.instantiate();
  ref->mChatEntry = std::make_unique<ChatEntry>(chat_entry);
  return ref;
}

void ChatEntryRef::_bind_methods()
{
  godot::ClassDB::bind_method(D_METHOD("get_name"), &ChatEntryRef::get_name);

}

String ChatEntryRef::get_name()
{
  return String::utf8(mChatEntry->name.c_str());
}

const ChatEntry &ChatEntryRef::get()
{
  return *mChatEntry.get();
}
