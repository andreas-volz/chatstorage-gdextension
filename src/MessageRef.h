/*
 * MessageViewRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef MESSAGEVIEWREF_H_
#define MESSAGEVIEWREF_H_

// project public API
#include "chatstorage/Message.h"
#include "chatstorage/ChatStorage.h"
#include "ChatContextRef.h"
#include "MediaRef.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

// system
#include <memory>

using namespace godot;

class MessageRef : public RefCounted
{
  GDCLASS(MessageRef, RefCounted)

public:
  MessageRef() = default;
  ~MessageRef() override = default;

  static Ref<MessageRef> create_message_ref(ContextHandle context_handle, const Message &message);

  Ref<MediaRef> get_media() const;

  Ref<UserRef> get_sender() const;

  int64_t get_timestamp() const;

  String get_text() const;

protected:
  static void _bind_methods();

private:
  std::unique_ptr<Message> mMessage;
  ContextHandle mContextHandle;
};


#endif /* MESSAGEVIEWREF_H_ */
