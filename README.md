# cjhtmlparser
htmlparser on  windows  and  linux 

����gumbo-parser ��gumbo-query �����Ϊ�� �������� Windows��Linux�� html������
�����÷�����:
#pragma once
#include "stdafx.h"

#include "enumtest.cpp"

#include "gumbo-parser/Selector.h"

#include "gumbo-parser/Document.h"
#include "gumbo-parser/Selection.h"
#include "gumbo-parser/Node.h"

void test_parser() {
	std::string page("<h1><a>wrong link</a><a class=\"special\"\\>some link</a></h1>");
	CDocument doc;
	doc.parse(page.c_str());

	CSelection c = doc.find("h1 a.special");
	CNode node = c.nodeAt(0);
	printf("Node: %s\n", node.text().c_str());
	std::string content = page.substr(node.startPos(), node.endPos() - node.startPos());
	printf("Node: %s\n", content.c_str());
}

void test_html() {
	std::string page = "<html><div><span>1\n</span>2\n</div></html>";
	CDocument doc;
	doc.parse(page.c_str());
	CNode pNode = doc.find("div").nodeAt(0);
	std::string content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
	printf("Node: #%s#\n", content.c_str());
}

void test_escape() {
	std::string page = "<html><div><span id=\"that's\">1\n</span>2\n</div></html>";
	CDocument doc;
	doc.parse(page.c_str());
	CNode pNode = doc.find("span[id=\"that's\"]").nodeAt(0);
	std::string content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
	printf("Node: #%s#\n", content.c_str());
}

int main() {
	test_parser();
	test_html();
	test_escape();
}