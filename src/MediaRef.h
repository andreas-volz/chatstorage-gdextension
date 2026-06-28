/*
 * MediaViewRef.h
 *
 *      Author: Andreas Volz
 */

#ifndef MEDIAVIEWREF_H_
#define MEDIAVIEWREF_H_

// project public API
#include "chatstorage/Media.h"
#include "chatstorage/ChatStorage.h"
#include "ContextHandle.h"

// godot
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"
#include <godot_cpp/classes/image_texture.hpp>

// system
#include <memory>

using namespace godot;

class MediaRef : public RefCounted
{
  GDCLASS(MediaRef, RefCounted)

public:
  MediaRef() = default;
  ~MediaRef() override = default;

  // @formatter:off
  enum MediaTypeGodot {
    MEDIA_TYPE_NONE,
    MEDIA_TYPE_IMAGE,
    MEDIA_TYPE_VIDEO,
    MEDIA_TYPE_AUDIO
  };
// @formatter:on

  static Ref<MediaRef> create_media_ref(ContextHandle context_handle, const Media &media);

  int64_t get_media_size() const;

  String get_mime_type() const;

  int get_type() const;

  String get_path() const;

  Ref<ImageTexture> get_texture() const;

protected:
  static void _bind_methods();

private:
  std::unique_ptr<Media> mMedia;
  ContextHandle mContextHandle;
};

// enum binding
VARIANT_ENUM_CAST(MediaRef::MediaTypeGodot);

#endif /* MEDIAVIEWREF_H_ */
