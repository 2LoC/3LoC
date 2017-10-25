#pragma once

namespace tloc {

	///-------------------------------------------------------------------------
	/// Used to avoid code duplication for operators. Requires definition of
	/// operators == and <
	///
	/// @param object The type itself
	///-------------------------------------------------------------------------
#define TLOC_DECLARE_OPERATOR_NOT_EQUAL(object)\
	bool operator !=(object const& a_other) const { return !(operator==(a_other)); }
#define TLOC_DECLARE_OPERATORS(object) \
	TLOC_DECLARE_OPERATOR_NOT_EQUAL(object) \
	bool operator > (object const& a_other) const { return a_other.operator<(*this); }\
	bool operator <=(object const& a_other) const { return !(operator>(a_other)); }\
	bool operator >=(object const& a_other) const { return !(operator<(a_other)); }


	///-------------------------------------------------------------------------
	/// These macros allow you to declare getters and setters quickly. Note that in
	/// this engine member variables should not be accessed directly, even by the
	/// host class itself.
	/// Reason1: to maintain consistency
	/// Reason2: to allow devs to debug get/set operations
	///
	/// The following macros make it easier/quicker to declare and define getters
	/// and setters. The problem ofcourse is that we cannot break into macros. This
	/// is why only declarations are also provided which can be defined immediately
	/// or later by the developer to allow breaking into the getter/setter.
	///------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Getters

#define TLOC_DECL_GETTER(_type_, _name_)\
	_type_ _name_() const
#define TLOC_DECL_GETTER_NON_CONST(_type_, _name_)\
	_type_ _name_()
#define TLOC_DECL_GETTER_REF(_type_, _name_)\
	_type_&       _name_()
#define TLOC_DECL_GETTER_CONST_REF(_type_, _name_)\
	_type_ const & _name_() const

#define TLOC_DECL_AND_DEF_GETTER(_type_, _name_, _var_)\
	TLOC_DECL_GETTER(_type_, _name_) { return _var_; }

#define TLOC_DECL_AND_DEF_GETTER_NON_CONST(_type_, _name_, _var_)\
	TLOC_DECL_GETTER_NON_CONST(_type_, _name_) { return _var_; }

#define TLOC_DECL_AND_DEF_GETTER_REF(_type_, _name_, _var_)\
	TLOC_DECL_GETTER_REF(_type_, _name_) { return _var_; }
#define TLOC_DECL_AND_DEF_GETTER_CONST_REF(_type_, _name_, _var_)\
	TLOC_DECL_GETTER_CONST_REF(_type_, _name_) { return (_var_); }

	//------------------------------------------------------------------------
	// Setters

#define TLOC_DECL_SETTER(_type_, _name_)\
	void            _name_(_type_ const & a_in)

#define TLOC_DECL_SETTER_CHAIN(_type_, _name_)\
	this_type&      _name_(_type_ const & a_in)

#define TLOC_DECL_SETTER_BY_VALUE(_type_, _name_)\
	void            _name_(_type_ a_in)

#define TLOC_DECL_SETTER_BY_VALUE_CHAIN(_type_, _name_)\
	this_type&      _name_(_type_ a_in)

#define TLOC_DECL_AND_DEF_SETTER(_type_, _name_, _var_)\
	TLOC_DECL_SETTER(_type_, _name_) { _var_ = a_in; }

#define TLOC_DECL_AND_DEF_SETTER_BY_VALUE(_type_, _name_, _var_)\
	TLOC_DECL_SETTER_BY_VALUE(_type_, _name_) { _var_ = a_in; }

#define TLOC_DECL_AND_DEF_SETTER_CHAIN(_type_, _name_, _var_)\
	TLOC_DECL_SETTER_CHAIN(_type_, _name_) { _var_ = a_in; return *this; }

#define TLOC_DECL_AND_DEF_SETTER_BY_VALUE_CHAIN(_type_, _name_, _var_)\
	TLOC_DECL_SETTER_BY_VALUE_CHAIN(_type_, _name_) { _var_ = a_in; return *this; }

	// -----------------------------------------------------------------------
	// For parameters

	// This will declare and define getter/setter with the passed name. It
	// will also return *this (reference of the instance) to allow chaining
	// these methods.
	// NOTE: You need to typedef the class as this_type

	// Variable name is _var_
	// Getter name is _methodName_
	// Setter name is _methodName_

#define TLOC_DECL_PARAM_VAR(_type_, _methodName_, _var_)\
public:\
	this_type& _methodName_(_type_ a_value)\
	{\
		_var_ = a_value;\
		return *this;\
	}\
  _type_ _methodName_() const\
	{\
		return _var_;\
	}\
private:\
	_type_ _var_

#define TLOC_DECL_PARAM_VAR_REF(_type_, _methodName_, _var_)\
public:\
	this_type& _methodName_(const _type_& a_value)\
	{\
		_var_ = a_value;\
		return *this;\
	}\
  const _type_& _methodName_() const\
	{\
		return _var_;\
	}\
private:\
	_type_ _var_

	//------------------------------------------------------------------------
	// Expansions

#define TLOC_DECL_AND_DEF_GETTERS_REF(_type_, _name_, _var_)\
	TLOC_DECL_AND_DEF_GETTER_REF(_type_, _name_, _var_)\
	TLOC_DECL_AND_DEF_GETTER_CONST_REF(_type_, _name_, _var_)

	//////////////////////////////////////////////////////////////////////////
	// Miscellaneous

	// Sometimes we have to pass templates in macros where commas don't work.
	// There we'll have to use this macro
#define TLOC_COMMA ,

	// Idea taken from WildMagic5
	// Avoid warnings about unused variables.  This is designed for variables
	// that are exposed in debug configurations but are hidden in release
	// configurations.
#define TLOC_UNUSED(variable) (void)variable
#define TLOC_UNUSED_2(variable1, variable2) TLOC_UNUSED(variable1); TLOC_UNUSED(variable2)
#define TLOC_UNUSED_3(variable1, variable2, variable3) TLOC_UNUSED_2(variable1, variable2); TLOC_UNUSED(variable3)
#define TLOC_UNUSED_4(variable1, variable2, variable3, variable4) TLOC_UNUSED_3(variable1, variable2, variable3); TLOC_UNUSED(variable4)
#define TLOC_UNUSED_5(variable1, variable2, variable3, variable4, variable5) TLOC_UNUSED_4(variable1, variable2, variable3, variable4); TLOC_UNUSED(variable5)
#define TLOC_UNUSED_6(variable1, variable2, variable3, variable4, variable5, variable6) TLOC_UNUSED_5(variable1, variable2, variable3, variable4, variable5); TLOC_UNUSED(variable6)
#define TLOC_UNUSED_7(variable1, variable2, variable3, variable4, variable5, variable6, variable7) TLOC_UNUSED_6(variable1, variable2, variable3, variable4, variable5, variable6); TLOC_UNUSED(variable7)

	// If a source file is empty (usually because of #ifdef) then the linker will
	// generate the LNK4221 warning complaining that no symbols were found and hence
	// the archive member (in the library) will be inaccessible. In most cases, we
	// are intentionally leaving the source file empty. In those cases, the following
	// define can be used (taken from: http://stackoverflow.com/questions/1822887/what-is-the-best-way-to-eliminate-ms-visual-c-linker-warning-warning-lnk4221/1823024#1823024

#ifdef _MSC_VER
# define TLOC_INTENTIONALLY_EMPTY_SOURCE_FILE() \
	namespace { char NoEmptyFileDummy##__LINE__; }
# define TLOC_NOT_EMPTY_SOURCE_FILE() \
	namespace { char NoEmptyFileDummy##__LINE__; }
#else
# define TLOC_INTENTIONALLY_EMPTY_SOURCE_FILE()
# define TLOC_NOT_EMPTY_SOURCE_FILE()
#endif
};
