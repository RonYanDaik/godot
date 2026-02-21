#ifndef FE9E8B00_E4CC_4710_B84C_9BD94C4AE583
#define FE9E8B00_E4CC_4710_B84C_9BD94C4AE583

#ifdef TRACY_ENABLE
#include "modules/godot_tracy_dll/tracy/public/tracy/Tracy.hpp"
#include "modules/godot_tracy_dll/tracy/public/tracy/TracyC.h"

#define _GDT_VARNAME_CONCAT_B_(m_ignore, m_name) m_name
#define _GDT_VARNAME_CONCAT_A_(m_a, m_b, m_c) _GDT_VARNAME_CONCAT_B_(hello there, m_a##m_b##m_c)
#define _GDT_VARNAME_CONCAT_(m_a, m_b, m_c) _GDT_VARNAME_CONCAT_A_(m_a, m_b, m_c)
#define GDT_UNIQUE_NAME(m_name) _GDT_VARNAME_CONCAT_(m_name, _, __COUNTER__)
#define GDTracyZoneNN(m_zone_name) ZoneNamedN(GDT_UNIQUE_NAME(__godot_tracy_szone_), m_zone_name, true)
#define GDTracyDynN(ctx) TracyCZone(ctx, true); \
	                     const CharString c_zone_name##__COUNTER__ = to_string().utf8(); \
	                     TracyCZoneName(ctx, c_zone_name##__COUNTER__.ptr(), c_zone_name##__COUNTER__.size());\
	                     TracyCMessage(c_zone_name##__COUNTER__.ptr(),c_zone_name##__COUNTER__.size());
#else
#define GDTracyDynN(ctx) 
#define GDTracyZoneNN(ctx)
#endif
#endif /* FE9E8B00_E4CC_4710_B84C_9BD94C4AE583 */
