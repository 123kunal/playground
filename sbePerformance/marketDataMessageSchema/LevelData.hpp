/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MARKETDATAMESSAGESCHEMA_LEVELDATA_HPP_
#define _MARKETDATAMESSAGESCHEMA_LEVELDATA_HPP_

#if defined(SBE_HAVE_CMATH)
/* cmath needed for std::numeric_limits<double>::quiet_NaN() */
#  include <cmath>
#  define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#  define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#else
/* math.h needed for NAN */
#  include <math.h>
#  define SBE_FLOAT_NAN NAN
#  define SBE_DOUBLE_NAN NAN
#endif

#include <sbe/sbe.hpp>

using namespace sbe;

namespace marketDataMessageSchema {

class LevelData
{
private:
    char *buffer_;
    int offset_;
    int actingVersion_;

    inline void reset(char *buffer, const int offset, const int bufferLength, const int actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((offset > (bufferLength - 24)), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
        buffer_ = buffer;
        offset_ = offset;
        actingVersion_ = actingVersion;
    }

public:
    LevelData(void) : buffer_(NULL), offset_(0) {}

    LevelData(char *buffer, const int bufferLength, const int actingVersion)
    {
        reset(buffer, 0, bufferLength, actingVersion);
    }

    LevelData(const LevelData& codec) :
        buffer_(codec.buffer_), offset_(codec.offset_), actingVersion_(codec.actingVersion_) {}

#if __cplusplus >= 201103L
    LevelData(LevelData&& codec) :
        buffer_(codec.buffer_), offset_(codec.offset_), actingVersion_(codec.actingVersion_) {}

    LevelData& operator=(LevelData&& codec)
    {
        buffer_ = codec.buffer_;
        offset_ = codec.offset_;
        actingVersion_ = codec.actingVersion_;
        return *this;
    }

#endif

    LevelData& operator=(const LevelData& codec)
    {
        buffer_ = codec.buffer_;
        offset_ = codec.offset_;
        actingVersion_ = codec.actingVersion_;
        return *this;
    }

    LevelData &wrap(char *buffer, const int offset, const int actingVersion, const int bufferLength)
    {
        reset(buffer, offset, bufferLength, actingVersion);
        return *this;
    }

    static const int size(void)
    {
        return 24;
    }


    static const sbe_double_t priceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static const sbe_double_t priceMinValue()
    {
        return 4.9E-324;
    }

    static const sbe_double_t priceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    sbe_double_t price(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_double_t *)(buffer_ + offset_ + 0)));
    }

    LevelData &price(const sbe_double_t value)
    {
        *((sbe_double_t *)(buffer_ + offset_ + 0)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t totalQtyNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static const sbe_uint64_t totalQtyMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t totalQtyMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t totalQty(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 8)));
    }

    LevelData &totalQty(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 8)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t numberOfOrdersNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static const sbe_uint64_t numberOfOrdersMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t numberOfOrdersMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t numberOfOrders(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 16)));
    }

    LevelData &numberOfOrders(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 16)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
#endif
