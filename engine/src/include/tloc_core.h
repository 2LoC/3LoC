#pragma once

#include <memory>

namespace tloc
{
#define TLOC_POINTER_IMPL(_name_)\
  class _name_;\
  std::unique_ptr<_name_>

#define TLOC_TYPEDEF_UNIQUE_PTR_NAME(_type_, _typedef_)\
  typedef std::unique_ptr<_type_>  _typedef_##_uptr;\
  typedef std::unique_ptr<const _type_>  const_##_typedef_##_uptr

#define TLOC_TYPEDEF_SHARED_PTR_NAME(_type_, _typedef_)\
  typedef std::shared_ptr<_type_>  _typedef_##_sptr;\
  typedef std::shared_ptr<const _type_>  const_##_typedef_##_sptr

#define TLOC_TYPEDEF_UNIQUE_PTR(_type_)\
	TLOC_TYPEDEF_UNIQUE_PTR_NAME(_type_, _type_)

#define TLOC_TYPEDEF_SHARED_PTR(_type_)\
	TLOC_TYPEDEF_SHARED_PTR_NAME(_type_, _type_)
};
