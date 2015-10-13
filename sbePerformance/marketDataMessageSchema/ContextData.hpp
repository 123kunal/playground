/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MARKETDATAMESSAGESCHEMA_CONTEXTDATA_HPP_
#define _MARKETDATAMESSAGESCHEMA_CONTEXTDATA_HPP_

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

class ContextData
{
private:
    char *buffer_;
    int offset_;
    int actingVersion_;

    inline void reset(char *buffer, const int offset, const int bufferLength, const int actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((offset > (bufferLength - 32)), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
        buffer_ = buffer;
        offset_ = offset;
        actingVersion_ = actingVersion;
    }

public:
    ContextData(void) : buffer_(NULL), offset_(0) {}

    ContextData(char *buffer, const int bufferLength, const int actingVersion)
    {
        reset(buffer, 0, bufferLength, actingVersion);
    }

    ContextData(const ContextData& codec) :
        buffer_(codec.buffer_), offset_(codec.offset_), actingVersion_(codec.actingVersion_) {}

#if __cplusplus >= 201103L
    ContextData(ContextData&& codec) :
        buffer_(codec.buffer_), offset_(codec.offset_), actingVersion_(codec.actingVersion_) {}

    ContextData& operator=(ContextData&& codec)
    {
        buffer_ = codec.buffer_;
        offset_ = codec.offset_;
        actingVersion_ = codec.actingVersion_;
        return *this;
    }

#endif

    ContextData& operator=(const ContextData& codec)
    {
        buffer_ = codec.buffer_;
        offset_ = codec.offset_;
        actingVersion_ = codec.actingVersion_;
        return *this;
    }

    ContextData &wrap(char *buffer, const int offset, const int actingVersion, const int bufferLength)
    {
        reset(buffer, offset, bufferLength, actingVersion);
        return *this;
    }

    static const int size(void)
    {
        return 32;
    }


    static const sbe_uint64_t bookSequenceNumberNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static const sbe_uint64_t bookSequenceNumberMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t bookSequenceNumberMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t bookSequenceNumber(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 0)));
    }

    ContextData &bookSequenceNumber(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 0)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t exchangeSequenceNumberNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static const sbe_uint64_t exchangeSequenceNumberMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t exchangeSequenceNumberMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t exchangeSequenceNumber(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 8)));
    }

    ContextData &exchangeSequenceNumber(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 8)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t feedHandlerTimeNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static const sbe_uint64_t feedHandlerTimeMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t feedHandlerTimeMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t feedHandlerTime(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 16)));
    }

    ContextData &feedHandlerTime(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 16)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static const sbe_uint64_t exchangeTimeNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static const sbe_uint64_t exchangeTimeMinValue()
    {
        return 0x0L;
    }

    static const sbe_uint64_t exchangeTimeMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    sbe_uint64_t exchangeTime(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((sbe_uint64_t *)(buffer_ + offset_ + 24)));
    }

    ContextData &exchangeTime(const sbe_uint64_t value)
    {
        *((sbe_uint64_t *)(buffer_ + offset_ + 24)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
#endif
