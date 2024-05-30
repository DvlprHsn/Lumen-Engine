#pragma once

#include <iostream>
#include <exception>
#include <iomanip>
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <sstream>

#ifdef LUMEN_PLATFORM_WIN32
#include <Windows.h>
#elif defined LUMEN_PLATFORM_WIN64
#include <Windows.h>
#endif
