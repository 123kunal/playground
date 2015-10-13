/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MARKETDATAMESSAGESCHEMA_VARDATAENCODING_HPP_
#define _MARKETDATAMESSAGESCHEMA_VARDATAENCODING_HPP_

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

class VarDataEncoding
{
private:
    char *buffer_;
    int offset_;
    int actingVersion_;

    inline void reset(char *buffer, const int offset, const int bufferLength, const int actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((offset > (bufferLength - -1)), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
        buffer_ = buffer;
        offset_ = offset;
        actingVersion_ = actingVersion;
    }

public:
    VarDataEncoding(void) : buffer_(NULL), offset_(0) {}

    VarDataEncoding(char *buffer, const int bufferLength, const int actingVersion)
    {
        reset(buffer, 0, bufferLength, actingVersion);
    }

    VarDataEncoding(const VarDataEncoding& codec) :
        buffer_(codec.buffer_), offset_(codec.offset_), actingVersion_(codec.actingVersion_) {}

#if __cplusplus >= 201103L
    VarDataEncoding(VarDataEncoding&& codec) :
        buffer_(codec.buffer_), offset_(codec.offset_), actingVersion_(codec.actingVersion_) {}

    VarDataEncoding& operator=(VarDataEncoding&& codec)
    {
        buffer_ = codec.buffer_;
        offset_ = codec.offset_;
        actingVersion_ = codec.actingVersion_;
        return *this;
    }

#endif

    VarDataEncoding& operator=(const VarDataEncoding& codec)
    {
        buffer_ = codec.buffer_;
        offset_ = codec.offset_;
        actingVersion_ = codec.actingVersion_;
        return *this;
    }

    VarDataEncoding &wrap(char *buffer, const int offset, const int actingVersion, const int bufferLength)
    {
        reset(buffer, offset, bufferLength, actingVersion);
        return *this;
    }

    static const int size(void)
    {
        return -1;
    }


    static const sbe_uint8_t lengthNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static const sbe_uint8_t lengthMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t lengthMaxValue()
    {
        return (sbe_uint8_t)254;
    }

    sbe_uint8_t length(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + offset_ + 0)));
    }

    VarDataEncoding &length(const sbe_uint8_t value)
    {
        *((sbe_uint8_t *)(buffer_ + offset_ + 0)) = (value);
        return *this;
    }

    static const sbe_uint8_t varDataNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static const sbe_uint8_t varDataMinValue()
    {
        return (sbe_uint8_t)0;
    }

    static const sbe_uint8_t varDataMaxValue()
    {
        return (sbe_uint8_t)254;
    }
};
}
#endif
