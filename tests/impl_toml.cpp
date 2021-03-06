#include "settings.h"
#if !TOML_ALL_INLINE
	#define TOML_IMPLEMENTATION
#endif

#if USE_TARTANLLAMA_OPTIONAL
	#if __has_include(<tloptional/include/tl/optional.hpp>)
		#include <tloptional/include/tl/optional.hpp>
	#else
		#error TartanLlama/optional is missing! You probably need to fetch submodules ("git submodule update --init extern/tloptional")
	#endif
#endif

#if USE_SINGLE_HEADER
	#include "../toml.hpp"
#else
	#include "../include/toml++/toml.h"
#endif

#if TOML_COMPILER_EXCEPTIONS != TOML_EXCEPTIONS
	#error TOML_EXCEPTIONS does not match TOML_COMPILER_EXCEPTIONS (default behaviour should be to match)
#endif

TOML_PUSH_WARNINGS
TOML_DISABLE_ALL_WARNINGS
#include <ostream>
TOML_POP_WARNINGS

namespace toml
{
	using std::declval;
	using std::is_same_v;

	static_assert(is_same_v<decltype(declval<node&>().ref<double>()), double&>);
	static_assert(is_same_v<decltype(declval<node&&>().ref<double>()), double&&>);
	static_assert(is_same_v<decltype(declval<const node&>().ref<double>()), const double&>);
	static_assert(is_same_v<decltype(declval<node&>().ref<value<double>>()), double&>);
	static_assert(is_same_v<decltype(declval<node&&>().ref<value<double>>()), double&&>);
	static_assert(is_same_v<decltype(declval<const node&>().ref<value<double>>()), const double&>);
	static_assert(is_same_v<decltype(declval<node&>().ref<table>()), table&>);
	static_assert(is_same_v<decltype(declval<node&&>().ref<table>()), table&&>);
	static_assert(is_same_v<decltype(declval<const node&>().ref<table>()), const table&>);
	static_assert(is_same_v<decltype(declval<node&>().ref<array>()), array&>);
	static_assert(is_same_v<decltype(declval<node&&>().ref<array>()), array&&>);
	static_assert(is_same_v<decltype(declval<const node&>().ref<array>()), const array&>);

	static_assert(is_same_v<decltype(declval<node_view<node>>().ref<double>()), double&>);
	static_assert(is_same_v<decltype(declval<node_view<const node>>().ref<double>()), const double&>);
	static_assert(is_same_v<decltype(declval<node_view<node>>().ref<value<double>>()), double&>);
	static_assert(is_same_v<decltype(declval<node_view<const node>>().ref<value<double>>()), const double&>);
	static_assert(is_same_v<decltype(declval<node_view<node>>().ref<table>()), table&>);
	static_assert(is_same_v<decltype(declval<node_view<const node>>().ref<table>()), const table&>);
	static_assert(is_same_v<decltype(declval<node_view<node>>().ref<array>()), array&>);
	static_assert(is_same_v<decltype(declval<node_view<const node>>().ref<array>()), const array&>);
}
