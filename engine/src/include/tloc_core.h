#pragma once

#include <memory>

#include "tloc_types.h"

namespace tloc
{
#define TLOC_POINTER_IMPL(_name_)\
  class _name_;\
  std::unique_ptr<_name_>

#define TLOC_TYPEDEF_UNIQUE_PTR_NAME(_type_, _typedef_)\
  using _typedef_##_uptr = std::unique_ptr<_type_>;\
  using const_##_typedef_##_uptr = std::unique_ptr<const _type_>

#define TLOC_TYPEDEF_SHARED_PTR_NAME(_type_, _typedef_)\
  using _typedef_##_sptr = std::shared_ptr<_type_>;\
  using const_##_typedef_##_sptr = std::shared_ptr<const _type_>

#define TLOC_TYPEDEF_UNIQUE_PTR(_type_)\
	TLOC_TYPEDEF_UNIQUE_PTR_NAME(_type_, _type_)

#define TLOC_TYPEDEF_SHARED_PTR(_type_)\
	TLOC_TYPEDEF_SHARED_PTR_NAME(_type_, _type_)
};
