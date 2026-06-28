/*
 * MediaViewRef.cpp
 *
 *      Author: Andreas Volz
 */

#include "MediaRef.h"

Ref<MediaRef> MediaRef::create_media_ref(ContextHandle context_handle, const Media &media)
{
  Ref<MediaRef> ref;
  ref.instantiate();
  ref->mContextHandle = context_handle;
  ref->mMedia = std::make_unique<Media>(media);
  return ref;
}

void MediaRef::_bind_methods()
{
  godot::ClassDB::bind_method(D_METHOD("get_media_size"), &MediaRef::get_media_size);
  godot::ClassDB::bind_method(D_METHOD("get_mime_type"), &MediaRef::get_mime_type);
  godot::ClassDB::bind_method(D_METHOD("get_type"), &MediaRef::get_type);
  godot::ClassDB::bind_method(D_METHOD("get_texture"), &MediaRef::get_texture);
  godot::ClassDB::bind_method(D_METHOD("get_path"), &MediaRef::get_path);

  BIND_ENUM_CONSTANT(MEDIA_TYPE_NONE);
  BIND_ENUM_CONSTANT(MEDIA_TYPE_IMAGE);
  BIND_ENUM_CONSTANT(MEDIA_TYPE_VIDEO);
  BIND_ENUM_CONSTANT(MEDIA_TYPE_AUDIO);
}

int64_t MediaRef::get_media_size() const
{
  return mMedia->getMediaSize();
}

String MediaRef::get_mime_type() const
{
  return String::utf8(mMedia->getMimeType().c_str());
}

int MediaRef::get_type() const
{
  return static_cast<int>(mMedia->getType());
}

String MediaRef::get_path() const
{
    std::filesystem::path media_path = mContextHandle.storage->getMediaPersistencePath();

    // this use of getDatabaseId() is required here as we left the consistent runtime id are and
    // access the files which are name according to database IDs
    media_path.append(std::to_string(mMedia->getDatabaseId()) + "." + mMedia->getMediaExtension());

    return String::utf8(media_path.u8string().c_str());
}

Ref<ImageTexture> MediaRef::get_texture() const
{
  String media_load_path = get_path();

  Ref<Image> image = memnew(Image);
  if (image->load(media_load_path) != OK)
  {
    print_error("Couldn't load image: " + media_load_path);
    return Ref<ImageTexture>();
  }

  return ImageTexture::create_from_image(image);
}
