/*
 * ContextHandle.h
 *
 *      Author: Andreas Volz
 */

#ifndef CONTEXTHANDLE_H_
#define CONTEXTHANDLE_H_

// forward declarations
class ChatStorage;
class ChatContext;

struct ContextHandle
{
  ChatStorage *storage = nullptr;
  ChatContext *context = nullptr;

  bool is_valid() const
  {
    return storage && context;
  }
};



#endif /* CONTEXTHANDLE_H_ */
