#include <iostream>
#include "MyTime.h"
#include <string>
#include "MarketDataSchema_generated.h"
#include <stdio.h>

using namespace std;

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
         _sid(0),_level(),_feedName("btechitch")
    {}
    LevelInfo(const Context& ctx_, uint32_t sid, const Level& level_, const std::string feed = "")
        :_ctx(ctx_),
         _sid(sid),_level(level_),_feedName(feed)
    {}
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
    void reset(const marketDataSchema::LevelInfoMessage* lvlInfoMesasge)
    {
        const marketDataSchema::ContextData* data = lvlInfoMesasge->contextData();
	_ctx._bookSequenceNumber 	= data->bookSequenceNumber();
        _ctx._exchangeSequenceNumber 	= data->exchangeSequenceNumber();
	_ctx._fhTime			= data->feedHandlerTime();
	_ctx._exchTime			= data->exchangeTime();
	
	_sid				= lvlInfoMesasge->sid();
	const marketDataSchema::LevelData* lvlData = lvlInfoMesasge->levelData();
	_level._price 		= lvlData->price();
      	_level._totalQty	= lvlData->totalQty();
	_level._numOfOrders	= lvlData->numberOfOrders();
	
	//_feedName		= lvlInfoMesasge->feedName()->str();
    }
    Context     _ctx;
    uint32_t    _sid;
    Level       _level;
    std::string _feedName;
};

