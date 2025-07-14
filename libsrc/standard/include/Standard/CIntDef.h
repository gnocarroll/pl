#pragma once

#ifdef __cplusplus
using USize = decltype(sizeof(0));
#else
typedef typeof(sizeof(0)) USize;
#endif