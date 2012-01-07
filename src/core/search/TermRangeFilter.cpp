/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "LuceneInc.h"
#include "TermRangeFilter.h"
#include "TermRangeQuery.h"
#include "StringUtils.h"
#include "VariantUtils.h"

namespace Lucene
{
    TermRangeFilter::TermRangeFilter(const String& fieldName, StringValue lowerTerm, StringValue upperTerm, bool includeLower,
                                     bool includeUpper, CollatorPtr collator) :
                                     MultiTermQueryWrapperFilter(newLucene<TermRangeQuery>(fieldName, lowerTerm, upperTerm,
                                     includeLower, includeUpper, collator))
    {
    }

    TermRangeFilter::~TermRangeFilter()
    {
    }

    TermRangeFilterPtr TermRangeFilter::Less(const String& fieldName, StringValue upperTerm)
    {
        return newLucene<TermRangeFilter>(fieldName, VariantUtils::null(), upperTerm, false, true);
    }

    TermRangeFilterPtr TermRangeFilter::More(const String& fieldName, StringValue lowerTerm)
    {
        return newLucene<TermRangeFilter>(fieldName, lowerTerm, VariantUtils::null(), true, false);
    }

    String TermRangeFilter::getField()
    {
        return gc_ptr_static_cast<TermRangeQuery>(query)->getField();
    }

    String TermRangeFilter::getLowerTerm()
    {
        return gc_ptr_static_cast<TermRangeQuery>(query)->getLowerTerm();
    }

    String TermRangeFilter::getUpperTerm()
    {
        return gc_ptr_static_cast<TermRangeQuery>(query)->getUpperTerm();
    }

    bool TermRangeFilter::includesLower()
    {
        return gc_ptr_static_cast<TermRangeQuery>(query)->includesLower();
    }

    bool TermRangeFilter::includesUpper()
    {
        return gc_ptr_static_cast<TermRangeQuery>(query)->includesUpper();
    }

    CollatorPtr TermRangeFilter::getCollator()
    {
        return gc_ptr_static_cast<TermRangeQuery>(query)->getCollator();
    }
}
