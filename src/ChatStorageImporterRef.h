/*
 * ChatStorageImporterRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef SRC_CHATSTORAGEIMPORTERREF_H_
#define SRC_CHATSTORAGEIMPORTERREF_H_

// project
#include "chatstorage/ChatStorageImporter.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class ChatStorageImporterRef : public RefCounted
{
  GDCLASS(ChatStorageImporterRef, RefCounted)

public:
  ChatStorageImporterRef() = default;
  ~ChatStorageImporterRef() override = default;

protected:
  static void _bind_methods();

private:
  std::unique_ptr<ChatStorageImporter> mStorageImporter;
};

#endif /* SRC_CHATSTORAGEIMPORTERREF_H_ */
