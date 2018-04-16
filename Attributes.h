#ifndef Attributes_h
#define Attributes_h



enum Attribute { ACC = 0, AGI, BAL, SPD, STA, STR, AGG, ANT, BRA, CRE, DET, FLA, INF, TEA, WOR, CHE, DEF, DEK, FAC, HIT, GTO, PAS, POK, POS, SLA, STI, WRI };
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


#endif
