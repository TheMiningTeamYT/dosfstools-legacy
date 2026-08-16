#ifndef ENDIAN_COMPAT_H
#define ENDIAN_COMPAT_H

#if defined(HAVE_ENDIAN_H)
#include <endian.h>
#if __GLIBC__ && __GLIBC__ <= 2 && __GLIBC_MINOR__ < 9
	#if __BYTE_ORDER == __BIG_ENDIAN
		#define htobe16(x) (x)
		#define htole16(x) __builtin_bswap16(x)
		#define be16toh(x) (x)
		#define le16toh(x) __builtin_bswap16(x)

		#define htobe32(x) (x)
		#define htole32(x) __builtin_bswap32(x)
		#define be32toh(x) (x)
		#define le32toh(x) __builtin_bswap32(x)

		#define htobe64(x) (x)
		#define htole64(x) __builtin_bswap64(x)
		#define be64toh(x) (x)
		#define le64toh(x) __builtin_bswap64(x)
	#elif __BYTE_ORDER == __LITTLE_ENDIAN
		#define htobe16(x) __builtin_bswap16(x)
		#define htole16(x) (x)
		#define be16toh(x) __builtin_bswap16(x)
		#define le16toh(x) (x)

		#define htobe32(x) __builtin_bswap32(x)
		#define htole32(x) (x)
		#define be32toh(x) __builtin_bswap32(x)
		#define le32toh(x) (x)

		#define htobe64(x) __builtin_bswap64(x)
		#define htole64(x) (x)
		#define be64toh(x) __builtin_bswap64(x)
		#define le64toh(x) (x)
	#else
		#error No endian.h available and no fallback code (sorry PDP users)
	#endif
#endif
#elif defined(HAVE_SYS_ENDIAN_H)
#include <sys/endian.h>
#elif defined(HAVE_LIBKERN_OSBYTEORDER_H)
	#include <libkern/OSByteOrder.h>

	#define htobe16(x) OSSwapHostToBigInt16(x)
	#define htole16(x) OSSwapHostToLittleInt16(x)
	#define be16toh(x) OSSwapBigToHostInt16(x)
	#define le16toh(x) OSSwapLittleToHostInt16(x)

	#define htobe32(x) OSSwapHostToBigInt32(x)
	#define htole32(x) OSSwapHostToLittleInt32(x)
	#define be32toh(x) OSSwapBigToHostInt32(x)
	#define le32toh(x) OSSwapLittleToHostInt32(x)

	#define htobe64(x) OSSwapHostToBigInt64(x)
	#define htole64(x) OSSwapHostToLittleInt64(x)
	#define be64toh(x) OSSwapBigToHostInt64(x)
	#define le64toh(x) OSSwapLittleToHostInt64(x)
#else
#error No endian.h available and no fallback code
#endif

#endif
