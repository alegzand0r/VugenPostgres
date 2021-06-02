Action()
{
	int n;
	
	lr_db_connect("StepName=connect",
		"ConnectionName=MyConnection",
		"ConnectionString=Driver={PostgreSQL Unicode};Database=mydb;Server=s-msk-t-perf-db;Port=5432;Uid=myuser;Pwd=mypass;",
		"ConnectionType=ODBC",
		LAST);
	
	n = lr_db_executeSQLStatement("StepName=PerformQuery", 
		"ConnectionName=MyConnection", 
		"SQLStatement=select * "
		"from loadtable2",
		"DatasetName=MyDataset", 
		LAST );
	
	lr_save_int(n, "NumOfRows");
		
	lr_db_getvalue("StepName=GetValue",   
		"DatasetName=MyDataset", 
		"Column=v1", 
		"Row=next", 
		"OutParam=MyOutputParam", 
		LAST );
	
	lr_db_disconnect("StepName=Disconnect", 
		"ConnectionName=MyConnection", LAST );
	
	return 0;
}
