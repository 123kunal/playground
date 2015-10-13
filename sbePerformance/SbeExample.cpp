#include <iostream>
#include "MyTime.h"
#include <string>

#include <stdio.h>

#include "marketDataMessageSchema/MessageHeader.hpp"
#include "marketDataMessageSchema/LevelInfoMesage.hpp"

using namespace std;
using namespace marketDataMessageSchema;

#if defined(WIN32) || defined(_WIN32)
#    define snprintf _snprintf
#endif /* WIN32 */

char VEHICLE_CODE[] = {'a', 'b', 'c', 'd', 'e', 'f'};
char MANUFACTURER_CODE[] = {'1', '2', '3'};
const char *MAKE = "Honda";
const char *MODEL = "Civic VTi";
const int messageHeaderVersion = 0;

uint64_t BOOK_SEQ_NUMBER = 1;
uint64_t EXCH_SEQ_NUMBER = 2;

struct Context
{
    Context()
        :_bookSequenceNumber(0),
         _exchangeSequenceNumber(0),
         _fhTime(0),
         _exchTime(0)
    {}
    Context(uint64_t bseq, uint64_t exchSeq, uint64_t fhtime, uint64_t extime)
        :_bookSequenceNumber(bseq),
         _exchangeSequenceNumber(exchSeq),
         _fhTime(fhtime),
         _exchTime(extime)
    {}
    bool operator==(const Context& rhs)
    {
        return _bookSequenceNumber 	== rhs._bookSequenceNumber &&
	       _exchangeSequenceNumber	== rhs._exchangeSequenceNumber &&
	       _fhTime			== rhs._fhTime &&
               _exchTime		== rhs._exchTime;
    }
    friend std::ostream& operator<< (std::ostream& stream, const Context& ctx)
    {
	stream  << "_bookSequenceNumber= " << ctx._bookSequenceNumber
	    	<< " _exchangeSequenceNumber= " << ctx._exchangeSequenceNumber
		<< " _fhTime= " << ctx._fhTime
		<< " _exchTime= " << ctx._exchTime << std::endl;
	return stream;
    }
    uint64_t     _bookSequenceNumber;
    uint64_t     _exchangeSequenceNumber;
    uint64_t     _fhTime;
    uint64_t     _exchTime;
    
};
struct Level
{
    Level()
        :_price(0.0),
        _totalQty(0),
        _numOfOrders(0)
    {}
    Level(double price, uint64_t totalQty, uint64_t numOrders)
        :_price(price),
        _totalQty(totalQty),
        _numOfOrders(numOrders)
    {}
    bool operator==(const Level& rhs)
    {
        return _price		== rhs._price &&
 	       _totalQty	== rhs._totalQty &&
	       _numOfOrders	== rhs._numOfOrders;
    }
    friend std::ostream& operator<< (std::ostream& stream, const Level& level)
    {
	stream  << "_price= " << level._price
	    	<< " _totalQty- = " << level._totalQty
		<< " _numOfOrders= " << level._numOfOrders << std::endl;
	return stream;
    }
    double      _price;
    uint64_t    _totalQty;
    uint64_t    _numOfOrders;
};
struct LevelInfo
{
    LevelInfo()
        :_ctx(),
         _sid(0),_level(),_feedName()
    {}
    LevelInfo(const Context& ctx_, uint32_t sid, const Level& level_, const std::string feed = "")
        :_ctx(ctx_),
         _sid(sid),_level(level_),_feedName(feed)
    {}
    void reset(LevelInfoMesage& levelInfoMesage)
    {
      ContextData& ctxData = levelInfoMesage.ctx();
      _ctx._bookSequenceNumber = ctxData.bookSequenceNumber();
      _ctx._exchangeSequenceNumber	= ctxData.exchangeSequenceNumber();
      _ctx._fhTime			= ctxData.feedHandlerTime();
      _ctx._exchTime			= ctxData.exchangeTime();
      _sid 				= levelInfoMesage.sid();

      LevelData& levelData = levelInfoMesage.levelData();
      _level._price	= levelData.price();
      _level._totalQty	= levelData.totalQty();
      _level._numOfOrders = levelData.numberOfOrders();

      char buf[1024];
      int bytesCopied = levelInfoMesage.getFeedName(buf, sizeof(buf));
      _feedName.append(buf,bytesCopied);
    }
    bool operator==(const LevelInfo& rhs)
    {
        return _ctx		== rhs._ctx &&
	       _sid		== rhs._sid &&
	       _level 		== rhs._level &
	       _feedName	== rhs._feedName;
    }
    friend std::ostream& operator<< (std::ostream& stream, const LevelInfo& levelInfo)
    {
	stream  << "\nCtx:\n " << levelInfo._ctx
	    	<< " \nsid= " <<levelInfo._sid 
	    	<< " \nLevel:\n" <<levelInfo._level
		<< " \nFeedName= " << levelInfo._feedName << std::endl;
	return stream;
    }
    Context     _ctx;
    uint32_t    _sid;
    Level       _level;
    std::string _feedName;
};



void encodeHdr(MessageHeader &hdr, LevelInfoMesage &levelInfoMesage, char *buffer, int offset, int bufferLength)
{
    // encode the header
    hdr.wrap(buffer, offset, messageHeaderVersion, bufferLength)
       .blockLength(LevelInfoMesage::sbeBlockLength())
       .templateId(LevelInfoMesage::sbeTemplateId())
       .schemaId(LevelInfoMesage::sbeSchemaId())
       .version(LevelInfoMesage::sbeSchemaVersion());
}

void decodeHdr(MessageHeader &hdr, char *buffer, int offset, int bufferLength)
{
    hdr.wrap(buffer, offset, messageHeaderVersion, bufferLength);

    // decode the header
    //cout << "messageHeader.blockLength=" << hdr.blockLength() << endl;
    //cout << "messageHeader.templateId=" << hdr.templateId() << endl;
    //cout << "messageHeader.schemaId=" << hdr.schemaId() << endl;
    //cout << "messageHeader.schemaVersion=" << (sbe_uint32_t)hdr.version() << endl;
}

void encodeLevelInfoMesage(const LevelInfo& levelInfo, LevelInfoMesage &levelInfoMesage, 
			   char *buffer, int offset, int bufferLength)
{
    levelInfoMesage.wrapForEncode(buffer, offset, bufferLength);

    levelInfoMesage.ctx()
       .bookSequenceNumber(levelInfo._ctx._bookSequenceNumber)
       .exchangeSequenceNumber(levelInfo._ctx._exchangeSequenceNumber)
       .feedHandlerTime(levelInfo._ctx._fhTime)
       .exchangeTime(levelInfo._ctx._exchTime);

    levelInfoMesage.sid(levelInfo._sid);

    levelInfoMesage.levelData()
	.price(levelInfo._level._price)
 	.totalQty(levelInfo._level._totalQty)
	.numberOfOrders(levelInfo._level._numOfOrders);


    levelInfoMesage.putFeedName(levelInfo._feedName.c_str(), levelInfo._feedName.length());
}

void decodeLevelInfoMesage(LevelInfoMesage &levelInfoMesage, char *buffer, int offset, 
			   int actingBlockLength, int actingVersion, int bufferLength)
{
    levelInfoMesage.wrapForDecode(buffer, offset, actingBlockLength, actingVersion, bufferLength);
}

int main(int argc, const char* argv[])
{
    MyTime encoding("ENCODING");
    MyTime decoding("DECODING");;
    for(int i = 0 ; i < SAMPLE_SIZE ; ++i)
    {
	    char buffer[2048];
	    Context ctx(BOOK_SEQ_NUMBER+i, EXCH_SEQ_NUMBER+i, BOOK_SEQ_NUMBER+i,EXCH_SEQ_NUMBER+i);
	    Level level(99.9876,101+i,21+i);
	    LevelInfo levelInfo(ctx,i,level,"btechitch");
	    MessageHeader hdr;
	    LevelInfoMesage levelInfoMesage;
	    LevelInfoMesage levelInfoMesage2;
	    //std::cout << "Bfr: " << levelInfo << std::endl;

		encoding.start();
		encodeHdr(hdr, levelInfoMesage, buffer, 0, sizeof(buffer));
		encodeLevelInfoMesage(levelInfo,levelInfoMesage, buffer, hdr.size(), sizeof(buffer));
		encoding.stop();
		//cout << "Encoding size is " << hdr.size() << " + " << levelInfoMesage.size() << endl;
		decoding.start();
		decodeHdr(hdr, buffer, 0, sizeof(buffer));
		decodeLevelInfoMesage(levelInfoMesage2, buffer, hdr.size(), hdr.blockLength(), hdr.version(), 
				  sizeof(buffer));
		decoding.stop();

	    LevelInfo levelInfo2;
	    //std::cout << "Afr: " << levelInfo2 << std::endl;
	    levelInfo2.reset(levelInfoMesage2);
	    //std::cout << "Afr: " << levelInfo2 << std::endl;
	    if(levelInfo == levelInfo2)
	    {
		//std::cout << "Rambo... all is good!!!" << std::endl;
	    }
	    else
	    {
		std::cout << "Rambo... smt is still wrong!!!" << std::endl;
	    }
    }
    encoding.dumpStat();
    decoding.dumpStat();
    return 0;
}
