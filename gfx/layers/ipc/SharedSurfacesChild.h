/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef MOZILLA_GFX_SHAREDSURFACESCHILD_H
#define MOZILLA_GFX_SHAREDSURFACESCHILD_H

#include <stddef.h>                     // for size_t
#include <stdint.h>                     // for uint32_t, uint64_t
#include "mozilla/Attributes.h"         // for override
#include "mozilla/RefPtr.h"             // for already_AddRefed
#include "mozilla/StaticPtr.h"          // for StaticRefPtr
#include "mozilla/webrender/WebRenderTypes.h" // for wr::ExternalImageId

namespace mozilla {
namespace gfx {
class SourceSurfaceSharedData;
} // namespace gfx

namespace layers {

class CompositorManagerChild;

class SharedSurfacesChild final
{
public:
  static nsresult Share(gfx::SourceSurfaceSharedData* aSurface, wr::ExternalImageId& aId);
  static nsresult Share(ImageContainer* aContainer, wr::ExternalImageId& aId, uint32_t& aGeneration);

private:
  SharedSurfacesChild() = delete;
  ~SharedSurfacesChild() = delete;

  class SharedUserData;

  static void Unshare(const wr::ExternalImageId& aId);
  static void DestroySharedUserData(void* aClosure);
};

} // namespace layers
} // namespace mozilla

#endif
