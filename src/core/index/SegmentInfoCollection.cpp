/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "LuceneInc.h"
#include "SegmentInfoCollection.h"
#include "SegmentInfo.h"

namespace Lucene
{
    SegmentInfoCollection::SegmentInfoCollection()
    {
        segmentInfos = Collection<SegmentInfoPtr>::newInstance();
    }

    SegmentInfoCollection::~SegmentInfoCollection()
    {
    }

    int32_t SegmentInfoCollection::size()
    {
        return segmentInfos.size();
    }

    bool SegmentInfoCollection::empty()
    {
        return segmentInfos.empty();
    }

    void SegmentInfoCollection::clear()
    {
        segmentInfos.clear();
    }

    void SegmentInfoCollection::add(SegmentInfoPtr info)
    {
        segmentInfos.add(info);
    }

    void SegmentInfoCollection::add(int32_t pos, SegmentInfoPtr info)
    {
        segmentInfos.add(pos, info);
    }

    void SegmentInfoCollection::add(SegmentInfoCollectionPtr segmentInfos)
    {
        this->segmentInfos.add(segmentInfos->segmentInfos.begin(), segmentInfos->segmentInfos.end());
    }

    bool SegmentInfoCollection::equals(SegmentInfoCollectionPtr other)
    {
        if (LuceneObject::equals(other))
            return true;
        return segmentInfos.equals(other->segmentInfos, luceneEquals<SegmentInfoPtr>());
    }

    int32_t SegmentInfoCollection::find(SegmentInfoPtr info)
    {
        Collection<SegmentInfoPtr>::iterator idx = segmentInfos.findIf(luceneEqualTo<SegmentInfoPtr>(info));
        return idx == segmentInfos.end() ? -1 : std::distance(segmentInfos.begin(), idx);
    }

    bool SegmentInfoCollection::contains(SegmentInfoPtr info)
    {
        return segmentInfos.containsIf(luceneEqualTo<SegmentInfoPtr>(info));
    }

    void SegmentInfoCollection::remove(int32_t pos)
    {
        segmentInfos.remove(segmentInfos.begin() + pos);
    }

    void SegmentInfoCollection::remove(int32_t start, int32_t end)
    {
        segmentInfos.remove(segmentInfos.begin() + start, segmentInfos.begin() + end);
    }

    LuceneObjectPtr SegmentInfoCollection::clone(LuceneObjectPtr other)
    {
        LuceneObjectPtr clone = LuceneObject::clone(other ? other : newLucene<SegmentInfoCollection>());
        SegmentInfoCollectionPtr cloneInfos(gc_ptr_dynamic_cast<SegmentInfoCollection>(clone));
        for (Collection<SegmentInfoPtr>::iterator info = segmentInfos.begin(); info != segmentInfos.end(); ++info)
            cloneInfos->segmentInfos.add(*info);
        return cloneInfos;
    }
}
