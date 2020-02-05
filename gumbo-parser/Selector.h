/***************************************************************************
 * 
 * $Id$
 * 
 **************************************************************************/

/**
 * @file $HeadURL$
 * @author $Author$(hoping@baimashi.com)
 * @date $Date$
 * @version $Revision$
 * @brief 
 *  
 **/

#ifndef SELECTOR_H_
#define SELECTOR_H_

#include <gumbo.h>
#include <string>
#include <vector>
#include "Object.h"

class CSelector: public CObject
{

	public:
		typedef enum   TOperator
		{
			//
			EDummy,
			//
			EEmpty,
			//
			EOnlyChild,
			//
			ENthChild,
			//
			ETag,
		} TOperator;
	public:

		CSelector(TOperator aOp = TOperator::EDummy)
		{
			init();
			mOp = aOp;
		}

		CSelector(bool aOfType)
		{
			init();
			mOp = TOperator::EOnlyChild;
			mOfType = aOfType;
		}

		CSelector(unsigned int aA, unsigned int aB, bool aLast, bool aOfType)
		{
			init();
			mOp = TOperator::ENthChild;
			mA = aA;
			mB = aB;
			mLast = aLast;
			mOfType = aOfType;
		}

		CSelector(GumboTag aTag)
		{
			init();
			mOp = TOperator::ETag;
			mTag = aTag;
		}

		virtual ~CSelector()
		{
		}

	public:

		virtual bool match(GumboNode* apNode);

		std::vector<GumboNode*> filter(std::vector<GumboNode*> nodes);

		std::vector<GumboNode*> matchAll(GumboNode* apNode);

	private:

		void init()
		{
			mOfType = false;
			mA = 0;
			mB = 0;
			mLast = false;
			mTag = GumboTag(0);
		}

		void matchAllInto(GumboNode* apNode, std::vector<GumboNode*>& nodes);

	private:

		TOperator mOp;

		bool mOfType;

		unsigned int mA;

		unsigned int mB;

		bool mLast;

		GumboTag mTag;
};

class CUnarySelector: public CSelector
{
	public:
		typedef enum  UTOperator
		{
			//
			ENot,
			//
			EHasDescendant,
			//
			EHasChild,
		} UTOperator;

	public:

		CUnarySelector(UTOperator aOp, CSelector* apS);

		virtual ~CUnarySelector();

	public:

		virtual bool match(GumboNode* apNode);

	private:

		bool hasDescendantMatch(GumboNode* apNode, CSelector* apS);

		bool hasChildMatch(GumboNode* apNode, CSelector* apS);

	private:

		CSelector* mpS;

		UTOperator mOp;
};

class CBinarySelector: public CSelector
{
	public:
		typedef enum  BTOperator
		{
			// || 操作符
			EUnion,
			// && 操作符
			EIntersection,
			//
			EChild,
			//
			EDescendant,
			//
			EAdjacent,
		} BTOperator;
		//using namespace CBinarySelector;
	public:

		CBinarySelector(CBinarySelector::BTOperator aOp, CSelector* apS1, CSelector* apS2);

		CBinarySelector(CSelector* apS1, CSelector* apS2, bool aAdjacent);

		~CBinarySelector();

	public:

		virtual bool match(GumboNode* apNode);

	private:

		CSelector* mpS1;

		CSelector* mpS2;

		BTOperator mOp;

		bool mAdjacent;
};

class CAttributeSelector: public CSelector
{
	public:
		typedef enum  ATOperator
		{
			/**
			 * 是否存在
			 */
			EExists,
			/**
			 * 是否相等
			 */
			EEquals,
			/**
			 * 是否包含
			 */
			EIncludes,
			/**
			 * 是否-开始
			 */
			EDashMatch,
			/**
			 * 是否前缀
			 */
			EPrefix,
			/**
			 * 是否后缀
			 */
			ESuffix,
			/**
			 * 是否子串
			 */
			ESubString,
		} ATOperator;

	public:

		CAttributeSelector(ATOperator aOp, std::string aKey, std::string aValue = "");

	public:

		virtual bool match(GumboNode* apNode);

	private:

		std::string mKey;

		std::string mValue;

		ATOperator mOp;
};

class CTextSelector: public CSelector
{
	public:
		typedef enum  TTOperator
		{
			//
			EOwnContains,
			//
			EContains,
		} TTOperator;

	public:
		CTextSelector(TTOperator aOp, std::string aValue)
		{
			mValue = aValue;
			mOp = aOp;
		}

		~CTextSelector()
		{
		}

	public:

		virtual bool match(GumboNode* apNode);

	private:

	private:

		std::string mValue;

		TTOperator mOp;
};

#endif /* SELECTOR_H_ */

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
