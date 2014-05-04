

#pragma once
typedef struct ZcCell
{
    int     mnRow;
    int     mnColumn;

} ZcCell;

typedef ZcArray<ZcCell> ZcCellArray;

typedef struct ZcCellRange
{
    int     mnTopRow;
    int     mnLeftColumn;
    int     mnBottomRow;
    int     mnRightColumn;

	ZcCellRange() : mnTopRow(0)
		, mnLeftColumn(0)
		, mnBottomRow(0)
		, mnRightColumn(0) {}

	bool operator ==(const ZcCellRange& range) const
	{
		return (mnTopRow      == range.mnTopRow &&
			mnLeftColumn  == range.mnLeftColumn &&
			mnBottomRow   == range.mnBottomRow &&
			mnRightColumn == range.mnRightColumn);
	}

	bool operator !=(const ZcCellRange& range) const
	{
		return !(mnTopRow      == range.mnTopRow &&
			mnLeftColumn  == range.mnLeftColumn &&
			mnBottomRow   == range.mnBottomRow &&
			mnRightColumn == range.mnRightColumn);
	}
} ZcCellRange;

typedef ZcArray<ZcCellRange> ZcCellRangeArray;
