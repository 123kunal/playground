/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MARKETDATAMESSAGESCHEMA_LEVELINFOMESAGE_HPP_
#define _MARKETDATAMESSAGESCHEMA_LEVELINFOMESAGE_HPP_

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

#include <marketDataMessageSchema/ContextData.hpp>
#include <marketDataMessageSchema/LevelData.hpp>
#include <marketDataMessageSchema/VarDataEncoding.hpp>

using namespace sbe;

namespace marketDataMessageSchema {

class LevelInfoMesage
{
private:
    char *buffer_;
    int bufferLength_;
    int *positionPtr_;
    int offset_;
    int position_;
    int actingBlockLength_;
    int actingVersion_;

    inline void reset(char *buffer, const int offset, const int bufferLength, const int actingBlockLength, const int actingVersion)
    {
        buffer_ = buffer;
        offset_ = offset;
        bufferLength_ = bufferLength;
        actingBlockLength_ = actingBlockLength;
        actingVersion_ = actingVersion;
        positionPtr_ = &position_;
        position(offset + actingBlockLength_);
    }

public:

    LevelInfoMesage(void) : buffer_(NULL), bufferLength_(0), offset_(0) {}

    LevelInfoMesage(char *buffer, const int bufferLength, const int actingBlockLength, const int actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    LevelInfoMesage(const LevelInfoMesage& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
    }

#if __cplusplus >= 201103L
    LevelInfoMesage(LevelInfoMesage&& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
    }

    LevelInfoMesage& operator=(LevelInfoMesage&& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
        return *this;
    }

#endif

    LevelInfoMesage& operator=(const LevelInfoMesage& codec)
    {
        reset(codec.buffer_, codec.offset_, codec.bufferLength_, codec.actingBlockLength_, codec.actingVersion_);
        return *this;
    }

    static const sbe_uint16_t sbeBlockLength(void)
    {
        return (sbe_uint16_t)60;
    }

    static const sbe_uint16_t sbeTemplateId(void)
    {
        return (sbe_uint16_t)1;
    }

    static const sbe_uint16_t sbeSchemaId(void)
    {
        return (sbe_uint16_t)1;
    }

    static const sbe_uint16_t sbeSchemaVersion(void)
    {
        return (sbe_uint16_t)0;
    }

    static const char *sbeSemanticType(void)
    {
        return "";
    }

    sbe_uint64_t offset(void) const
    {
        return offset_;
    }

    LevelInfoMesage &wrapForEncode(char *buffer, const int offset, const int bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    LevelInfoMesage &wrapForDecode(char *buffer, const int offset, const int actingBlockLength, const int actingVersion, const int bufferLength)
    {
        reset(buffer, offset, bufferLength, actingBlockLength, actingVersion);
        return *this;
    }

    sbe_uint64_t position(void) const
    {
        return position_;
    }

    void position(const int position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > bufferLength_), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        position_ = position;
    }

    int size(void) const
    {
        return position() - offset_;
    }

    char *buffer(void)
    {
        return buffer_;
    }

    int actingVersion(void) const
    {
        return actingVersion_;
    }

    static const int ctxId(void)
    {
        return 1;
    }

    static const int ctxSinceVersion(void)
    {
         return 0;
    }

    bool ctxInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *ctxMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

private:
    ContextData ctx_;

public:

    ContextData &ctx(void)
    {
        ctx_.wrap(buffer_, offset_ + 0, actingVersion_, bufferLength_);
        return ctx_;
    }

    static const int sidId(void)
    {
        return 2;
    }

    static const int sidSinceVersion(void)
    {
         return 0;
    }

    bool sidInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *sidMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const sbe_uint32_t sidNullValue()
    {
        return SBE_NULLVALUE_UINT32;
    }

    static const sbe_uint32_t sidMinValue()
    {
        return 0;
    }

    static const sbe_uint32_t sidMaxValue()
    {
        return 4294967293;
    }

    sbe_uint32_t sid(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_uint32_t *)(buffer_ + offset_ + 32)));
    }

    LevelInfoMesage &sid(const sbe_uint32_t value)
    {
        *((sbe_uint32_t *)(buffer_ + offset_ + 32)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static const int levelDataId(void)
    {
        return 3;
    }

    static const int levelDataSinceVersion(void)
    {
         return 0;
    }

    bool levelDataInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *levelDataMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

private:
    LevelData levelData_;

public:

    LevelData &levelData(void)
    {
        levelData_.wrap(buffer_, offset_ + 36, actingVersion_, bufferLength_);
        return levelData_;
    }

    static const char *feedNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static const char *feedNameCharacterEncoding()
    {
        return "UTF-8";
    }

    static const int feedNameSinceVersion(void)
    {
         return 0;
    }

    bool feedNameInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }

    static const int feedNameId(void)
    {
        return 4;
    }


    static const int feedNameHeaderSize()
    {
        return 1;
    }

    sbe_int64_t feedNameLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + position())));
    }

    const char *feedName(void)
    {
         const char *fieldPtr = (buffer_ + position() + 1);
         position(position() + 1 + *((sbe_uint8_t *)(buffer_ + position())));
         return fieldPtr;
    }

    int getFeedName(char *dst, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + lengthOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)dataLength);
        ::memcpy(dst, buffer_ + pos, bytesToCopy);
        return bytesToCopy;
    }

    int putFeedName(const char *src, const int length)
    {
        sbe_uint64_t lengthOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        position(lengthPosition + lengthOfLengthField);
        sbe_uint64_t pos = position();
        position(position() + (sbe_uint64_t)length);
        ::memcpy(buffer_ + pos, src, length);
        return length;
    }
};
}
#endif
