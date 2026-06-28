/*
 * UserViewRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef USERVIEWREF_H_
#define USERVIEWREF_H_

// project
#include "chatstorage/User.h"
#include "ContextHandle.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

// system
#include <memory>

using namespace godot;

class UserRef : public RefCounted
{
  GDCLASS(UserRef, RefCounted)

public:
  UserRef() = default;
  ~UserRef() override = default;

  static Ref<UserRef> create_user_ref(ContextHandle context_handle, const User &user);

  String get_name() const;

  bool is_system() const;

protected:
  static void _bind_methods();

private:
  std::unique_ptr<User> mUser;
  ContextHandle mContextHandle;
};

#endif /* USERVIEWREF_H_ */
