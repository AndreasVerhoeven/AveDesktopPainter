#pragma once

#include "stdafx.h"

class XMLHelper
{



public:
	XMLHelper(void);
	~XMLHelper(void);

	typedef CComPtr<IXMLDOMNode> NodePtr;

	static NodePtr getChildFromNode(NodePtr node, BSTR xpath)
	{
		if(NULL == node)
			return NULL;

		NodePtr child;
		node->selectSingleNode(xpath, &child);

		return child;
	}

	static CString getStringFromNode(NodePtr node, BSTR xpath, CString defaultValue=L"")
	{
		if(NULL == node)
			return defaultValue;

		NodePtr child;
		node->selectSingleNode(xpath, &child);
		if(NULL == child)
			return defaultValue;

		CComBSTR str;
		child->get_text(&str);
		
		return str != NULL ? static_cast<const WCHAR*>(str) : L"";
	}

	static CRect getRectFromNode(NodePtr node, BSTR xpath, CRect defaultValue)
	{
		CRect rc = defaultValue;

		NodePtr child;
		node->selectSingleNode(xpath, &child);
		if(NULL == child)
			return rc;

		long left	= getLongFromNode(child, L"left", defaultValue.left);
		long top	= getLongFromNode(child, L"top", defaultValue.top);
		long width	= getLongFromNode(child, L"width", defaultValue.Width());
		long height	= getLongFromNode(child, L"height", defaultValue.Height());

		rc.SetRect(left, top, left + width, top + height);

		return rc;
	}
	

	static Color getColorFromNode(NodePtr node, BSTR xpath, Color defaultColor)
	{
		BYTE a = defaultColor.GetAlpha();
		BYTE r = defaultColor.GetRed();
		BYTE g = defaultColor.GetGreen();
		BYTE b = defaultColor.GetBlue();

		NodePtr child;
		node->selectSingleNode(xpath, &child);
		if(NULL == child)
			return defaultColor;

		a = (BYTE)getLongFromNode(child, L"alpha", a);
		r = (BYTE)getLongFromNode(child, L"red", r);
		g = (BYTE)getLongFromNode(child, L"green", g);
		b = (BYTE)getLongFromNode(child, L"blue", b);

		return Color(a, r, g, b);
	}

	static long getLongFromNode(NodePtr node, BSTR xpath, LONG defaultValue)
	{
		LCID lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), 0);

		CString str = getStringFromNode(node, xpath);
		CComVariant val(str);

		HRESULT hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_I4);
		if(hRes != S_OK)
			return defaultValue;

		return val.lVal;
	}

	static float getFloatFromNode(NodePtr node, BSTR xpath, float defaultValue)
	{
		LCID lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), 0);

		CString str = getStringFromNode(node, xpath);

		CComVariant val(str);

		HRESULT hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_R4);
		if(hRes != S_OK)
			return defaultValue;

		return val.fltVal;
	}

	static BOOL getBoolFromNode(NodePtr node, BSTR xpath, BOOL defaultValue)
	{
		LCID lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), 0);

		CString str = getStringFromNode(node, xpath);
		CComVariant val(str);

		HRESULT hRes = VariantChangeTypeEx(&val, &val, lcid, VARIANT_NOUSEROVERRIDE, VT_BOOL);
		if(hRes != S_OK)
			return defaultValue;

		return val.boolVal != VARIANT_FALSE;
	}
};
