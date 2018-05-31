#ifndef Attributes_h
#define Attributes_h



enum Attribute { ACC = 0, AGI, BAL, SPD, STA, STR, AGG, ANT, BRA, CRE, DET, FLA, INF, TEA, WOR, CHE, DEF, DEK, FAC, HIT, GTO, PAS, POK, POS, SLA, STI, WRI };
//enum AttributeFLTR { ACC = 0, AGI, BAL, BRA, CRE, DEK, FAC, INF, PAS, POS, SLA, STA, STR, WOR, AGG, ANT, CHE, DEF, DET, FLA, HIT, GTO, POK, SPD, STI, TEA, WRI };
const char* getAttribute(enum Attribute attribute)
{
	switch (attribute)
	{
	case ACC: return "ACC";
	case AGI: return "AGI";
	case BAL: return "BAL";
	case SPD: return "SPD";
	case STA: return "STA";
	case STR: return "STR";
	case AGG: return "AGG";
	case ANT: return "ANT";
	case BRA: return "BRA";
	case CRE: return "CRE";
	case DET: return "DET";
	case FLA: return "FLA";
	case INF: return "INF";
	case TEA: return "TEA";
	case WOR: return "WOR";
	case CHE: return "CHE";
	case DEF: return "DEF";
	case DEK: return "DEK";
	case FAC: return "FAC";
	case HIT: return "HIT";
	case GTO: return "GTO";
	case PAS: return "PAS";
	case POK: return "POK";
	case POS: return "POS";
	case SLA: return "SLA";
	case STI: return "STI";
	case WRI: return "WRI";
	}
}

const char*getAttributeFLTR(int val)
{
	switch (val)
	{
	case 0: return "ACC";
	case 1: return "AGI";
	case 2: return "BAL";
	case 3: return "BRA";
	case 4: return "CRE";
	case 5: return "DEK";
	case 6: return "FAC";
	case 7: return "INF";
	case 8: return "PAS";
	case 9: return "POS";
	case 10: return "SLA";
	case 11: return "STA";
	case 12: return "STR";
	case 13: return "WOR";
	case 14: return "AGG";
	case 15: return "ANT";
	case 16: return "CHE";
	case 17: return "DEF";
	case 18: return "DET";
	case 19: return "FLA";
	case 20: return "HIT";
	case 21: return "GTO";
	case 22: return "POK";
	case 23: return "SPD";
	case 24: return "STI";
	case 25: return "TEA";
	case 26: return "WRI";
	}
}


#endif
