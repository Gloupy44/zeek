
%include binpac.pac
%include bro.pac

analyzer Unified2 withcontext {
	analyzer:   Unified2_Analyzer;
	flow:       Flow;
};

analyzer Unified2_Analyzer {
	downflow = Flow;
	upflow   = Flow;
};

%include unified2-file.pac

flow Flow {
	flowunit = File withcontext(connection, this);
};

%include unified2-analyzer.pac
