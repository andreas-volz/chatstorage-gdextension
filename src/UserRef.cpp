/*
 * UserViewRef.cpp
 *
 *      Author: Andreas Volz
 */

#include "UserRef.h"

Ref<UserRef> UserRef::create_user_ref(ContextHandle context_handle, const User &user)
{
  Ref<UserRef> ref;
  ref.instantiate();
  ref->mUser = std::make_unique<User>(user);
  ref->mContextHandle = context_handle;
  return ref;
}

void UserRef::_bind_methods()
{
  godot::ClassDB::bind_method(D_METHOD("get_name"), &UserRef::get_name);
  godot::ClassDB::bind_method(D_METHOD("is_system"), &UserRef::is_system);
}

String UserRef::get_name() const
{
  return String::utf8(mUser->getName().c_str());
}

bool UserRef::is_system() const
{
  return mUser->isSystem();
}

