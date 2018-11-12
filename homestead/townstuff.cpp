#include "pch.h"
#include "ioStuff.h"
#include "townstuff.h"
#include "homestead.h"

void townOptions()
{
	int x{ printTownOptions() };
	if (x == 1)
	{
		visitLivestockStore();
	}
	if (x == 2)
	{
		visitGenStore();
	}
	if (x == 3)
	{
		visitToolStore();
	}
	else
		townError();
}

void visitLivestockStore()
{
	lsStoreMsg();
	choiceHandler();
}

void visitGenStore()
{
	genStoreMsg();
	choiceHandler();
}

void visitToolStore()
{
	toolStoreMsg();
	choiceHandler();
}