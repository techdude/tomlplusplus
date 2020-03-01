project(
	'tomlplusplus',
	'cpp',
	version : '0.3.0',
	license : 'MIT',
	default_options : [
		'cpp_std=c++17',
		'warning_level=3',
		'werror=true',
		'cpp_eh=default'
	]
)


compiler = meson.get_compiler('cpp')
message(['compiler ID: ', compiler.get_id()])

if compiler.get_id() == 'gcc'
	add_project_arguments([
			'-fmax-errors=5',
			'-Wno-attributes',
			'-Wno-init-list-lifetime'
		],
		language : 'cpp'
	)
endif

if compiler.get_id() == 'clang'
	add_project_arguments([
			'-g0',
			'-ferror-limit=5',
			'-fchar8_t',
			'-Wno-c++98-compat',
			'-Wno-c++98-compat-pedantic',
			'-Wno-float-equal',
			'-Wno-switch-enum',
			'-Wno-documentation-unknown-command',
			'-Wno-padded',
			'-Wno-weak-vtables',
			'-Wno-double-promotion'
			#, '-Weverything'
		],
		language : 'cpp'
	)
endif

if compiler.get_id() == 'intel-cl'
	add_project_arguments([
			'/Qoption,cpp,--unicode_source_kind,UTF-8',
			'/std=c++latest',
			'/wd82', # storage class is not first
			'/wd280', # selector expression is constant (why the fuck is that a warning?)
			'/wd411', # class provides no constructor (duh, it's an aggregate)
			'/wd1011', # missing return statement (false negative)
			'/wd1628', # function marked [[noreturn]] returns (false positive)
			'/wd3280' # declaration hides member (triggered in Catch2)
		],
		language : 'cpp'
	)
endif

compiler_supports_char8_strings = compiler.compiles('''
	#include <string_view>
	#include <string>
	using namespace std::string_view_literals;
	std::u8string func()
	{
		return std::u8string{ u8"this is a test."sv };
	}
	''',
	name : 'char8 string check',
	args : [ '-std=c++2a' ]
)

inc = include_directories(['include', 'extern'])

subdir('tests')
# subdir('examples')