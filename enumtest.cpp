#pragma once
#include "stdafx.h"
//class CSelector 
//{
//
//public:
//	typedef enum
//	{
//		//
//		EDummy,
//		//
//		EEmpty,
//		//
//		EOnlyChild,
//		//
//		ENthChild,
//		//
//		ETag,
//	} TOperator;
//public:
//
//	CSelector(TOperator aOp = EDummy)
//	{
//		mOp = aOp;
//	}
//
//	CSelector(bool aOfType)
//	{
//		mOp = EOnlyChild;
//		mOfType = aOfType;
//	}
//
//	CSelector(unsigned int aA, unsigned int aB, bool aLast, bool aOfType)
//	{
//		mOp = ENthChild;
//		mA = aA;
//		mB = aB;
//		mLast = aLast;
//		mOfType = aOfType;
//	}
//
//
//	virtual ~CSelector()
//	{
//	}
//
//public:
//
//
//private:
//
//
//
//private:
//
//	TOperator mOp;
//
//	bool mOfType;
//
//	unsigned int mA;
//
//	unsigned int mB;
//
//	bool mLast;
//
//};
//
//class CUnarySelector : public CSelector
//{
//public:
//	typedef enum
//	{
//		//
//		ENot,
//		//
//		EHasDescendant,
//		//
//		EHasChild,
//	} TOperator;
//
//public:
//
//	CUnarySelector(TOperator aOp, CSelector* apS)
//	{
//
//	}
//
//	virtual ~CUnarySelector()
//	{
//	}
//
//
//
//private:
//
//	CSelector * mpS;
//
//	TOperator mOp;
//};
//
//class CBinarySelector : public CSelector
//{
//public:
//	typedef enum TOperator
//	{
//		// || ²Ù×÷·û
//		EUnion,
//		// && ²Ù×÷·û
//		EIntersection,
//		//
//		EChild,
//		//
//		EDescendant,
//		//
//		EAdjacent,
//	} TOperator;
//	//using namespace CBinarySelector;
//public:
//
//	CBinarySelector(TOperator aOp, CSelector* apS1, CSelector* apS2)
//	{
//
//	}
//
//	CBinarySelector(CSelector* apS1, CSelector* apS2, bool aAdjacent)
//	{
//
//	}
//
//	~CBinarySelector()
//	{
//
//	}
//
//
//
//private:
//
//	CSelector * mpS1;
//
//	CSelector* mpS2;
//
//	TOperator mOp;
//
//	bool mAdjacent;
//};
//
