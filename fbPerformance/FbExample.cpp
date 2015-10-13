#include <iostream>
#include "include/flatbuffers/flatbuffers.h"
#include "InternalDataStructure.h"
#include "MarketDataSchema_generated.h"


using namespace marketDataSchema;

int main()
{
	
    	MyTime encoding("FLAT BUFFER ENCODING");
    	MyTime decoding("FLAT BUFFER DECODING");;
    	for(int i = 0 ; i < SAMPLE_SIZE ; ++i)
    	{
		Context ctx(BOOK_SEQ_NUMBER+i, EXCH_SEQ_NUMBER+i, BOOK_SEQ_NUMBER+i,EXCH_SEQ_NUMBER+i);
            	Level level(99.9876,101+i,21+i);
            	LevelInfo levelInfo(ctx,i,level,"btechitch");
		ContextData ctxData(levelInfo._ctx._bookSequenceNumber, levelInfo._ctx._exchangeSequenceNumber,
				    levelInfo._ctx._fhTime,levelInfo._ctx._exchTime); 

                LevelData levelData(levelInfo._level._price, levelInfo._level._totalQty, 
				    levelInfo._level._numOfOrders);
            	//std::cout << "Bfr: " << levelInfo << std::endl;

		flatbuffers::FlatBufferBuilder builder;

		//auto fhName = builder.CreateString(levelInfo._feedName);
		encoding.start();
		//auto lloc = CreateLevelInfoMessage(builder,&ctxData,i,&levelData,fhName);
		auto lloc = CreateLevelInfoMessage(builder,&ctxData,i,&levelData);
		encoding.stop();
		builder.Finish(lloc);

		uint8_t* data 	= builder.GetBufferPointer();
		//uint32_t size	= builder.GetSize();

		decoding.start();
		const LevelInfoMessage* lvlInfoMesasge = GetLevelInfoMessage(data);
		decoding.stop();

		builder.Clear();
		LevelInfo levelInfo2;
		levelInfo2.reset(lvlInfoMesasge);
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

