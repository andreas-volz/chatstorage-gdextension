/*
 * ChatViewRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef CHATVIEWREF_H_
#define CHATVIEWREF_H_

// project
#include "chatstorage/Chat.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

// system
#include <memory>

using namespace godot;

class ChatRef : public RefCounted
{
  GDCLASS(ChatRef, RefCounted)

public:
  ChatRef() = default;
  ~ChatRef() override = default;

// @formatter:off
  enum ChatSourceGodot {
    CHAT_SOURCE_FORMAT_A,
    CHAT_SOURCE_FORMAT_B
  };
// @formatter:on

  static Ref<ChatRef> create_object_ref(const Chat &chat);

  String get_name() const;

  int get_source() const;

protected:
  static void _bind_methods();

private:
  std::unique_ptr<Chat> mChat;
};

// enum binding
VARIANT_ENUM_CAST(ChatRef::ChatSourceGodot);

#endif /* CHATVIEWREF_H_ */
