#pragma once

// toml++ config
#define TOML_UNDEF_MACROS 0
#ifdef TEST_BUILD_ID
	#if (TEST_BUILD_ID % 3 == 0) && !defined(TOML_ALL_INLINE)
		#define TOML_ALL_INLINE 1
	#endif
	#if (TEST_BUILD_ID % 2 == 0) && !defined(USE_SINGLE_HEADER)
		#define USE_SINGLE_HEADER 1
	#endif
#endif
#ifndef TOML_ALL_INLINE
	#define TOML_ALL_INLINE 0
#endif
#ifndef USE_SINGLE_HEADER
	#define USE_SINGLE_HEADER 0
#endif

// use tl::optional?
#if defined(USE_TARTANLLAMA_OPTIONAL) && USE_TARTANLLAMA_OPTIONAL
	#define TOML_OPTIONAL_TYPE tl::optional
#else
	#undef USE_TARTANLLAMA_OPTIONAL
	#define USE_TARTANLLAMA_OPTIONAL 0
#endif

//catch2 config
#define CATCH_CONFIG_CPP11_TO_STRING
#define CATCH_CONFIG_CPP17_OPTIONAL
#define CATCH_CONFIG_CPP17_STRING_VIEW
#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_CONSOLE_WIDTH 120
#define CATCH_CONFIG_CPP11_TO_STRING
#define CATCH_CONFIG_DISABLE_MATCHERS

//windows.h config (included transitively by catch2 on windows)
#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define VC_EXTRALEAN
	#define NOATOM //            - Atom Manager routines
	#define NOBITMAP
	#define NOCLIPBOARD //       - Clipboard routines
	#define NOCOLOR //           - Screen colors
	#define NOCOMM //            - COMM driver routines
	#define NOCTLMGR //          - Control and Dialog routines
	#define NODEFERWINDOWPOS //  - DeferWindowPos routines
	#define NODRAWTEXT //        - DrawText() and DT_*
	#define NOGDI //             - All GDI defines and routines
	#define NOGDICAPMASKS //     - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
	#define NOHELP //            - Help engine interface.
	#define NOICONS //           - IDI_*
	#define NOKANJI //           - Kanji support stuff.
	#define NOKEYSTATES //       - MK_*
	#define NOKERNEL //          - All KERNEL defines and routines
	#define NOMB //              - MB_* and MessageBox()
	#define NOMCX //             - Modem Configuration Extensions
	#define NOMENUS //           - MF_*
	#define NOMEMMGR //          - GMEM_*, LMEM_*, GHND, LHND, associated routines
	#define NOMETAFILE //        - typedef METAFILEPICT
	#define NOMINMAX //          - Macros min(a,b) and max(a,b)
	#define NOMSG //             - typedef MSG and associated routines
	#define NONLS //             - All NLS defines and routines
	#define NOOPENFILE //        - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
	#define NOPROFILER //        - Profiler interface.
	#define NORASTEROPS //       - Binary and Tertiary raster ops
	#define NOSCROLL //          - SB_* and scrolling routines
	#define NOSERVICE //         - All Service Controller routines, SERVICE_ equates, etc.
	#define NOSHOWWINDOW //      - SW_*
	#define NOSOUND //           - Sound driver routines
	#define NOSYSCOMMANDS //     - SC_*
	#define NOSYSMETRICS //      - SM_*
	#define NOTEXTMETRIC //      - typedef TEXTMETRIC and associated routines
	#define NOUSER //            - All USER defines and routines
	#define NOVIRTUALKEYCODES // - VK_*
	#define NOWH //              - SetWindowsHook and WH_*
	#define NOWINOFFSETS //      - GWL_*, GCL_*, associated routines
	#define NOWINMESSAGES //     - WM_*, EM_*, LB_*, CB_*
	#define NOWINSTYLES //       - WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
#endif
