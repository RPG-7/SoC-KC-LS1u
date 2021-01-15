void TF_chushihua()
{
  unsigned char j_;

//////////////////复位为SPI模式//////////////////     

  SPI_CS = 0x10;  //SPI速率设置为4分频 并选中空设备
  
  for(j_ = 0;j_ != 8;++j_)SPI_D = 0xff; //发送80个时钟


  SPI_CS = 0x18; //设置速率并选中SD卡

  SPI_D = 0x40;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x95;
  while((SPI_INT & 0x80) != 0x80);

  SPI_S = 0x02; //SPI输出1

  while(SPI_D != 0x01) while((SPI_INT & 0x80) != 0x80); //读到0x01跳出


///////////////////初始化/////////////////////////

 while(SPI_D != 0x00)
 {

    SPI_S = 0x01; //SPI关闭输出1

    SPI_CS = 0x00; //选中空设备

    SPI_D = 0xff;   //填充8个时钟
    while((SPI_INT & 0x80) != 0x80);

    SPI_CS = 0x18; //设置速率并选中SD卡

    SPI_D = 0x41;
    while((SPI_INT & 0x80) != 0x80);
    SPI_D = 0x00;
    while((SPI_INT & 0x80) != 0x80);
    SPI_D = 0x00;
    while((SPI_INT & 0x80) != 0x80);
    SPI_D = 0x00;
    while((SPI_INT & 0x80) != 0x80);
    SPI_D = 0x00;
    while((SPI_INT & 0x80) != 0x80);
    SPI_D = 0xff;
    while((SPI_INT & 0x80) != 0x80);

    SPI_S = 0x02; //SPI输出1

    SPI_D = 0xff;
    while((SPI_INT & 0x80) != 0x80);
    SPI_D = 0xff;
    while((SPI_INT & 0x80) != 0x80);

 }

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);

}

void TF_RD(SQDZ3,SQDZ2,SQDZ1,SRAMaddr)	  //SQDZ为扇区地址  SRAMaddr为读出数据写入SRAM的首地址
{

  unsigned char j_;

  SPI_CS = 0x08;

  SPI_D = 0x51;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQDZ3;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQDZ2;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQDZ1;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);

  SPI_S = 0x02; //SPI输出1

  while(SPI_D != 0x00) while((SPI_INT & 0x80) != 0x80);
  while(SPI_D != 0xfe) while((SPI_INT & 0x80) != 0x80); //读到扇区数据起始标志0xfe跳出

  j_ = 0;
  while(j_ != 64)
  {

    SRAM[SRAMaddr++] = SPI_D;
    SRAM[SRAMaddr++] = SPI_D;
    SRAM[SRAMaddr++] = SPI_D;
    SRAM[SRAMaddr++] = SPI_D;
    SRAM[SRAMaddr++] = SPI_D;
    SRAM[SRAMaddr++] = SPI_D;
    SRAM[SRAMaddr++] = SPI_D;
    SRAM[SRAMaddr++] = SPI_D;

    ++j_;

  }

  SPI_D = 0xff;

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;

}


void TF_RD_ENC28J60(SQDZ3,SQDZ2,SQDZ1) //SQDZ为扇区地址  SRAMaddr为读出数据写入ENC28J60的首地址
{

  unsigned char j_;
  unsigned char DATA[512];

  SPI_CS = 0x08;

  SPI_D = 0x51;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQDZ3;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQDZ2;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQDZ1;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);

  SPI_S = 0x02; //SPI输出1

  while(SPI_D != 0x00) while((SPI_INT & 0x80) != 0x80);
  while(SPI_D != 0xfe) while((SPI_INT & 0x80) != 0x80); //读到扇区数据起始标志0xfe跳出


  DATA[0] = SPI_D;
  DATA[1] = SPI_D;
  DATA[2] = SPI_D;
  DATA[3] = SPI_D;
  DATA[4] = SPI_D;
  DATA[5] = SPI_D;
  DATA[6] = SPI_D;
  DATA[7] = SPI_D;

  DATA[8] = SPI_D;
  DATA[9] = SPI_D;
  DATA[10] = SPI_D;
  DATA[11] = SPI_D;
  DATA[12] = SPI_D;
  DATA[13] = SPI_D;
  DATA[14] = SPI_D;
  DATA[15] = SPI_D;

  DATA[16] = SPI_D;
  DATA[17] = SPI_D;
  DATA[18] = SPI_D;
  DATA[19] = SPI_D;
  DATA[20] = SPI_D;
  DATA[21] = SPI_D;
  DATA[22] = SPI_D;
  DATA[23] = SPI_D;

  DATA[24] = SPI_D;
  DATA[25] = SPI_D;
  DATA[26] = SPI_D;
  DATA[27] = SPI_D;
  DATA[28] = SPI_D;
  DATA[29] = SPI_D;
  DATA[30] = SPI_D;
  DATA[31] = SPI_D;

  DATA[32] = SPI_D;
  DATA[33] = SPI_D;
  DATA[34] = SPI_D;
  DATA[35] = SPI_D;
  DATA[36] = SPI_D;
  DATA[37] = SPI_D;
  DATA[38] = SPI_D;
  DATA[39] = SPI_D;

  DATA[40] = SPI_D;
  DATA[41] = SPI_D;
  DATA[42] = SPI_D;
  DATA[43] = SPI_D;
  DATA[44] = SPI_D;
  DATA[45] = SPI_D;
  DATA[46] = SPI_D;
  DATA[47] = SPI_D;

  DATA[48] = SPI_D;
  DATA[49] = SPI_D;
  DATA[50] = SPI_D;
  DATA[51] = SPI_D;
  DATA[52] = SPI_D;
  DATA[53] = SPI_D;
  DATA[54] = SPI_D;
  DATA[55] = SPI_D;

  DATA[56] = SPI_D;
  DATA[57] = SPI_D;
  DATA[58] = SPI_D;
  DATA[59] = SPI_D;
  DATA[60] = SPI_D;
  DATA[61] = SPI_D;
  DATA[62] = SPI_D;
  DATA[63] = SPI_D;

  DATA[64] = SPI_D;
  DATA[65] = SPI_D;
  DATA[66] = SPI_D;
  DATA[67] = SPI_D;
  DATA[68] = SPI_D;
  DATA[69] = SPI_D;
  DATA[70] = SPI_D;
  DATA[71] = SPI_D;

  DATA[72] = SPI_D;
  DATA[73] = SPI_D;
  DATA[74] = SPI_D;
  DATA[75] = SPI_D;
  DATA[76] = SPI_D;
  DATA[77] = SPI_D;
  DATA[78] = SPI_D;
  DATA[79] = SPI_D;

  DATA[80] = SPI_D;
  DATA[81] = SPI_D;
  DATA[82] = SPI_D;
  DATA[83] = SPI_D;
  DATA[84] = SPI_D;
  DATA[85] = SPI_D;
  DATA[86] = SPI_D;
  DATA[87] = SPI_D;

  DATA[88] = SPI_D;
  DATA[89] = SPI_D;
  DATA[90] = SPI_D;
  DATA[91] = SPI_D;
  DATA[92] = SPI_D;
  DATA[93] = SPI_D;
  DATA[94] = SPI_D;
  DATA[95] = SPI_D;

  DATA[96] = SPI_D;
  DATA[97] = SPI_D;
  DATA[98] = SPI_D;
  DATA[99] = SPI_D;
  DATA[100] = SPI_D;
  DATA[101] = SPI_D;
  DATA[102] = SPI_D;
  DATA[103] = SPI_D;

  DATA[104] = SPI_D;
  DATA[105] = SPI_D;
  DATA[106] = SPI_D;
  DATA[107] = SPI_D;
  DATA[108] = SPI_D;
  DATA[109] = SPI_D;
  DATA[110] = SPI_D;
  DATA[111] = SPI_D;

  DATA[112] = SPI_D;
  DATA[113] = SPI_D;
  DATA[114] = SPI_D;
  DATA[115] = SPI_D;
  DATA[116] = SPI_D;
  DATA[117] = SPI_D;
  DATA[118] = SPI_D;
  DATA[119] = SPI_D;

  DATA[120] = SPI_D;
  DATA[121] = SPI_D;
  DATA[122] = SPI_D;
  DATA[123] = SPI_D;
  DATA[124] = SPI_D;
  DATA[125] = SPI_D;
  DATA[126] = SPI_D;
  DATA[127] = SPI_D;

  DATA[128] = SPI_D;
  DATA[129] = SPI_D;
  DATA[130] = SPI_D;
  DATA[131] = SPI_D;
  DATA[132] = SPI_D;
  DATA[133] = SPI_D;
  DATA[134] = SPI_D;
  DATA[135] = SPI_D;

  DATA[136] = SPI_D;
  DATA[137] = SPI_D;
  DATA[138] = SPI_D;
  DATA[139] = SPI_D;
  DATA[140] = SPI_D;
  DATA[141] = SPI_D;
  DATA[142] = SPI_D;
  DATA[143] = SPI_D;

  DATA[144] = SPI_D;
  DATA[145] = SPI_D;
  DATA[146] = SPI_D;
  DATA[147] = SPI_D;
  DATA[148] = SPI_D;
  DATA[149] = SPI_D;
  DATA[150] = SPI_D;
  DATA[151] = SPI_D;

  DATA[152] = SPI_D;
  DATA[153] = SPI_D;
  DATA[154] = SPI_D;
  DATA[155] = SPI_D;
  DATA[156] = SPI_D;
  DATA[157] = SPI_D;
  DATA[158] = SPI_D;
  DATA[159] = SPI_D;

  DATA[160] = SPI_D;
  DATA[161] = SPI_D;
  DATA[162] = SPI_D;
  DATA[163] = SPI_D;
  DATA[164] = SPI_D;
  DATA[165] = SPI_D;
  DATA[166] = SPI_D;
  DATA[167] = SPI_D;

  DATA[168] = SPI_D;
  DATA[169] = SPI_D;
  DATA[170] = SPI_D;
  DATA[171] = SPI_D;
  DATA[172] = SPI_D;
  DATA[173] = SPI_D;
  DATA[174] = SPI_D;
  DATA[175] = SPI_D;

  DATA[176] = SPI_D;
  DATA[177] = SPI_D;
  DATA[178] = SPI_D;
  DATA[179] = SPI_D;
  DATA[180] = SPI_D;
  DATA[181] = SPI_D;
  DATA[182] = SPI_D;
  DATA[183] = SPI_D;

  DATA[184] = SPI_D;
  DATA[185] = SPI_D;
  DATA[186] = SPI_D;
  DATA[187] = SPI_D;
  DATA[188] = SPI_D;
  DATA[189] = SPI_D;
  DATA[190] = SPI_D;
  DATA[191] = SPI_D;

  DATA[192] = SPI_D;
  DATA[193] = SPI_D;
  DATA[194] = SPI_D;
  DATA[195] = SPI_D;
  DATA[196] = SPI_D;
  DATA[197] = SPI_D;
  DATA[198] = SPI_D;
  DATA[199] = SPI_D;

  DATA[200] = SPI_D;
  DATA[201] = SPI_D;
  DATA[202] = SPI_D;
  DATA[203] = SPI_D;
  DATA[204] = SPI_D;
  DATA[205] = SPI_D;
  DATA[206] = SPI_D;
  DATA[207] = SPI_D;

  DATA[208] = SPI_D;
  DATA[209] = SPI_D;
  DATA[210] = SPI_D;
  DATA[211] = SPI_D;
  DATA[212] = SPI_D;
  DATA[213] = SPI_D;
  DATA[214] = SPI_D;
  DATA[215] = SPI_D;

  DATA[216] = SPI_D;
  DATA[217] = SPI_D;
  DATA[218] = SPI_D;
  DATA[219] = SPI_D;
  DATA[220] = SPI_D;
  DATA[221] = SPI_D;
  DATA[222] = SPI_D;
  DATA[223] = SPI_D;

  DATA[224] = SPI_D;
  DATA[225] = SPI_D;
  DATA[226] = SPI_D;
  DATA[227] = SPI_D;
  DATA[228] = SPI_D;
  DATA[229] = SPI_D;
  DATA[230] = SPI_D;
  DATA[231] = SPI_D;

  DATA[232] = SPI_D;
  DATA[233] = SPI_D;
  DATA[234] = SPI_D;
  DATA[235] = SPI_D;
  DATA[236] = SPI_D;
  DATA[237] = SPI_D;
  DATA[238] = SPI_D;
  DATA[239] = SPI_D;

  DATA[240] = SPI_D;
  DATA[241] = SPI_D;
  DATA[242] = SPI_D;
  DATA[243] = SPI_D;
  DATA[244] = SPI_D;
  DATA[245] = SPI_D;
  DATA[246] = SPI_D;
  DATA[247] = SPI_D;

  DATA[248] = SPI_D;
  DATA[249] = SPI_D;
  DATA[250] = SPI_D;
  DATA[251] = SPI_D;
  DATA[252] = SPI_D;
  DATA[253] = SPI_D;
  DATA[254] = SPI_D;
  DATA[255] = SPI_D;

  DATA[256] = SPI_D;
  DATA[257] = SPI_D;
  DATA[258] = SPI_D;
  DATA[259] = SPI_D;
  DATA[260] = SPI_D;
  DATA[261] = SPI_D;
  DATA[262] = SPI_D;
  DATA[263] = SPI_D;

  DATA[264] = SPI_D;
  DATA[265] = SPI_D;
  DATA[266] = SPI_D;
  DATA[267] = SPI_D;
  DATA[268] = SPI_D;
  DATA[269] = SPI_D;
  DATA[270] = SPI_D;
  DATA[271] = SPI_D;

  DATA[272] = SPI_D;
  DATA[273] = SPI_D;
  DATA[274] = SPI_D;
  DATA[275] = SPI_D;
  DATA[276] = SPI_D;
  DATA[277] = SPI_D;
  DATA[278] = SPI_D;
  DATA[279] = SPI_D;

  DATA[280] = SPI_D;
  DATA[281] = SPI_D;
  DATA[282] = SPI_D;
  DATA[283] = SPI_D;
  DATA[284] = SPI_D;
  DATA[285] = SPI_D;
  DATA[286] = SPI_D;
  DATA[287] = SPI_D;

  DATA[288] = SPI_D;
  DATA[289] = SPI_D;
  DATA[290] = SPI_D;
  DATA[291] = SPI_D;
  DATA[292] = SPI_D;
  DATA[293] = SPI_D;
  DATA[294] = SPI_D;
  DATA[295] = SPI_D;

  DATA[296] = SPI_D;
  DATA[297] = SPI_D;
  DATA[298] = SPI_D;
  DATA[299] = SPI_D;
  DATA[300] = SPI_D;
  DATA[301] = SPI_D;
  DATA[302] = SPI_D;
  DATA[303] = SPI_D;

  DATA[304] = SPI_D;
  DATA[305] = SPI_D;
  DATA[306] = SPI_D;
  DATA[307] = SPI_D;
  DATA[308] = SPI_D;
  DATA[309] = SPI_D;
  DATA[310] = SPI_D;
  DATA[311] = SPI_D;

  DATA[312] = SPI_D;
  DATA[313] = SPI_D;
  DATA[314] = SPI_D;
  DATA[315] = SPI_D;
  DATA[316] = SPI_D;
  DATA[317] = SPI_D;
  DATA[318] = SPI_D;
  DATA[319] = SPI_D;

  DATA[320] = SPI_D;
  DATA[321] = SPI_D;
  DATA[322] = SPI_D;
  DATA[323] = SPI_D;
  DATA[324] = SPI_D;
  DATA[325] = SPI_D;
  DATA[326] = SPI_D;
  DATA[327] = SPI_D;

  DATA[328] = SPI_D;
  DATA[329] = SPI_D;
  DATA[330] = SPI_D;
  DATA[331] = SPI_D;
  DATA[332] = SPI_D;
  DATA[333] = SPI_D;
  DATA[334] = SPI_D;
  DATA[335] = SPI_D;

  DATA[336] = SPI_D;
  DATA[337] = SPI_D;
  DATA[338] = SPI_D;
  DATA[339] = SPI_D;
  DATA[340] = SPI_D;
  DATA[341] = SPI_D;
  DATA[342] = SPI_D;
  DATA[343] = SPI_D;

  DATA[344] = SPI_D;
  DATA[345] = SPI_D;
  DATA[346] = SPI_D;
  DATA[347] = SPI_D;
  DATA[348] = SPI_D;
  DATA[349] = SPI_D;
  DATA[350] = SPI_D;
  DATA[351] = SPI_D;

  DATA[352] = SPI_D;
  DATA[353] = SPI_D;
  DATA[354] = SPI_D;
  DATA[355] = SPI_D;
  DATA[356] = SPI_D;
  DATA[357] = SPI_D;
  DATA[358] = SPI_D;
  DATA[359] = SPI_D;

  DATA[360] = SPI_D;
  DATA[361] = SPI_D;
  DATA[362] = SPI_D;
  DATA[363] = SPI_D;
  DATA[364] = SPI_D;
  DATA[365] = SPI_D;
  DATA[366] = SPI_D;
  DATA[367] = SPI_D;

  DATA[368] = SPI_D;
  DATA[369] = SPI_D;
  DATA[370] = SPI_D;
  DATA[371] = SPI_D;
  DATA[372] = SPI_D;
  DATA[373] = SPI_D;
  DATA[374] = SPI_D;
  DATA[375] = SPI_D;

  DATA[376] = SPI_D;
  DATA[377] = SPI_D;
  DATA[378] = SPI_D;
  DATA[379] = SPI_D;
  DATA[380] = SPI_D;
  DATA[381] = SPI_D;
  DATA[382] = SPI_D;
  DATA[383] = SPI_D;

  DATA[384] = SPI_D;
  DATA[385] = SPI_D;
  DATA[386] = SPI_D;
  DATA[387] = SPI_D;
  DATA[388] = SPI_D;
  DATA[389] = SPI_D;
  DATA[390] = SPI_D;
  DATA[391] = SPI_D;

  DATA[392] = SPI_D;
  DATA[393] = SPI_D;
  DATA[394] = SPI_D;
  DATA[395] = SPI_D;
  DATA[396] = SPI_D;
  DATA[397] = SPI_D;
  DATA[398] = SPI_D;
  DATA[399] = SPI_D;

  DATA[400] = SPI_D;
  DATA[401] = SPI_D;
  DATA[402] = SPI_D;
  DATA[403] = SPI_D;
  DATA[404] = SPI_D;
  DATA[405] = SPI_D;
  DATA[406] = SPI_D;
  DATA[407] = SPI_D;

  DATA[408] = SPI_D;
  DATA[409] = SPI_D;
  DATA[410] = SPI_D;
  DATA[411] = SPI_D;
  DATA[412] = SPI_D;
  DATA[413] = SPI_D;
  DATA[414] = SPI_D;
  DATA[415] = SPI_D;

  DATA[416] = SPI_D;
  DATA[417] = SPI_D;
  DATA[418] = SPI_D;
  DATA[419] = SPI_D;
  DATA[420] = SPI_D;
  DATA[421] = SPI_D;
  DATA[422] = SPI_D;
  DATA[423] = SPI_D;

  DATA[424] = SPI_D;
  DATA[425] = SPI_D;
  DATA[426] = SPI_D;
  DATA[427] = SPI_D;
  DATA[428] = SPI_D;
  DATA[429] = SPI_D;
  DATA[430] = SPI_D;
  DATA[431] = SPI_D;

  DATA[432] = SPI_D;
  DATA[433] = SPI_D;
  DATA[434] = SPI_D;
  DATA[435] = SPI_D;
  DATA[436] = SPI_D;
  DATA[437] = SPI_D;
  DATA[438] = SPI_D;
  DATA[439] = SPI_D;

  DATA[440] = SPI_D;
  DATA[441] = SPI_D;
  DATA[442] = SPI_D;
  DATA[443] = SPI_D;
  DATA[444] = SPI_D;
  DATA[445] = SPI_D;
  DATA[446] = SPI_D;
  DATA[447] = SPI_D;

  DATA[448] = SPI_D;
  DATA[449] = SPI_D;
  DATA[450] = SPI_D;
  DATA[451] = SPI_D;
  DATA[452] = SPI_D;
  DATA[453] = SPI_D;
  DATA[454] = SPI_D;
  DATA[455] = SPI_D;

  DATA[456] = SPI_D;
  DATA[457] = SPI_D;
  DATA[458] = SPI_D;
  DATA[459] = SPI_D;
  DATA[460] = SPI_D;
  DATA[461] = SPI_D;
  DATA[462] = SPI_D;
  DATA[463] = SPI_D;

  DATA[464] = SPI_D;
  DATA[465] = SPI_D;
  DATA[466] = SPI_D;
  DATA[467] = SPI_D;
  DATA[468] = SPI_D;
  DATA[469] = SPI_D;
  DATA[470] = SPI_D;
  DATA[471] = SPI_D;

  DATA[472] = SPI_D;
  DATA[473] = SPI_D;
  DATA[474] = SPI_D;
  DATA[475] = SPI_D;
  DATA[476] = SPI_D;
  DATA[477] = SPI_D;
  DATA[478] = SPI_D;
  DATA[479] = SPI_D;

  DATA[480] = SPI_D;
  DATA[481] = SPI_D;
  DATA[482] = SPI_D;
  DATA[483] = SPI_D;
  DATA[484] = SPI_D;
  DATA[485] = SPI_D;
  DATA[486] = SPI_D;
  DATA[487] = SPI_D;

  DATA[488] = SPI_D;
  DATA[489] = SPI_D;
  DATA[490] = SPI_D;
  DATA[491] = SPI_D;
  DATA[492] = SPI_D;
  DATA[493] = SPI_D;
  DATA[494] = SPI_D;
  DATA[495] = SPI_D;

  DATA[496] = SPI_D;
  DATA[497] = SPI_D;
  DATA[498] = SPI_D;
  DATA[499] = SPI_D;
  DATA[500] = SPI_D;
  DATA[501] = SPI_D;
  DATA[502] = SPI_D;
  DATA[503] = SPI_D;

  DATA[504] = SPI_D;
  DATA[505] = SPI_D;
  DATA[506] = SPI_D;
  DATA[507] = SPI_D;
  DATA[508] = SPI_D;
  DATA[509] = SPI_D;
  DATA[510] = SPI_D;
  DATA[511] = SPI_D;


  SPI_D = 0xff;

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;

  while((SPI_INT & 0x80) != 0x80);






  SPI_CS = 0x09;
  SPI_D = 0xbf;  //选择bank0
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x03;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

  SPI_CS = 0x09;
  SPI_D = 0x02 | 0x40;  //EWRPTL 缓冲器写指针指向TCP数据首部
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x37;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

  SPI_CS = 0x09;
  SPI_D = 0x03 | 0x40;  //EWRPTH
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;


  SPI_CS = 0x09;

  SPI_D = 0x7a;

  SPI_D = DATA[0];
  SPI_D = DATA[1];
  SPI_D = DATA[2];
  SPI_D = DATA[3];
  SPI_D = DATA[4];
  SPI_D = DATA[5];
  SPI_D = DATA[6];
  SPI_D = DATA[7];

  SPI_D = DATA[8];
  SPI_D = DATA[9];
  SPI_D = DATA[10];
  SPI_D = DATA[11];
  SPI_D = DATA[12];
  SPI_D = DATA[13];
  SPI_D = DATA[14];
  SPI_D = DATA[15];

  SPI_D = DATA[16];
  SPI_D = DATA[17];
  SPI_D = DATA[18];
  SPI_D = DATA[19];
  SPI_D = DATA[20];
  SPI_D = DATA[21];
  SPI_D = DATA[22];
  SPI_D = DATA[23];

  SPI_D = DATA[24];
  SPI_D = DATA[25];
  SPI_D = DATA[26];
  SPI_D = DATA[27];
  SPI_D = DATA[28];
  SPI_D = DATA[29];
  SPI_D = DATA[30];
  SPI_D = DATA[31];

  SPI_D = DATA[32];
  SPI_D = DATA[33];
  SPI_D = DATA[34];
  SPI_D = DATA[35];
  SPI_D = DATA[36];
  SPI_D = DATA[37];
  SPI_D = DATA[38];
  SPI_D = DATA[39];

  SPI_D = DATA[40];
  SPI_D = DATA[41];
  SPI_D = DATA[42];
  SPI_D = DATA[43];
  SPI_D = DATA[44];
  SPI_D = DATA[45];
  SPI_D = DATA[46];
  SPI_D = DATA[47];

  SPI_D = DATA[48];
  SPI_D = DATA[49];
  SPI_D = DATA[50];
  SPI_D = DATA[51];
  SPI_D = DATA[52];
  SPI_D = DATA[53];
  SPI_D = DATA[54];
  SPI_D = DATA[55];

  SPI_D = DATA[56];
  SPI_D = DATA[57];
  SPI_D = DATA[58];
  SPI_D = DATA[59];
  SPI_D = DATA[60];
  SPI_D = DATA[61];
  SPI_D = DATA[62];
  SPI_D = DATA[63];

  SPI_D = DATA[64];
  SPI_D = DATA[65];
  SPI_D = DATA[66];
  SPI_D = DATA[67];
  SPI_D = DATA[68];
  SPI_D = DATA[69];
  SPI_D = DATA[70];
  SPI_D = DATA[71];

  SPI_D = DATA[72];
  SPI_D = DATA[73];
  SPI_D = DATA[74];
  SPI_D = DATA[75];
  SPI_D = DATA[76];
  SPI_D = DATA[77];
  SPI_D = DATA[78];
  SPI_D = DATA[79];

  SPI_D = DATA[80];
  SPI_D = DATA[81];
  SPI_D = DATA[82];
  SPI_D = DATA[83];
  SPI_D = DATA[84];
  SPI_D = DATA[85];
  SPI_D = DATA[86];
  SPI_D = DATA[87];

  SPI_D = DATA[88];
  SPI_D = DATA[89];
  SPI_D = DATA[90];
  SPI_D = DATA[91];
  SPI_D = DATA[92];
  SPI_D = DATA[93];
  SPI_D = DATA[94];
  SPI_D = DATA[95];

  SPI_D = DATA[96];
  SPI_D = DATA[97];
  SPI_D = DATA[98];
  SPI_D = DATA[99];
  SPI_D = DATA[100];
  SPI_D = DATA[101];
  SPI_D = DATA[102];
  SPI_D = DATA[103];

  SPI_D = DATA[104];
  SPI_D = DATA[105];
  SPI_D = DATA[106];
  SPI_D = DATA[107];
  SPI_D = DATA[108];
  SPI_D = DATA[109];
  SPI_D = DATA[110];
  SPI_D = DATA[111];

  SPI_D = DATA[112];
  SPI_D = DATA[113];
  SPI_D = DATA[114];
  SPI_D = DATA[115];
  SPI_D = DATA[116];
  SPI_D = DATA[117];
  SPI_D = DATA[118];
  SPI_D = DATA[119];

  SPI_D = DATA[120];
  SPI_D = DATA[121];
  SPI_D = DATA[122];
  SPI_D = DATA[123];
  SPI_D = DATA[124];
  SPI_D = DATA[125];
  SPI_D = DATA[126];
  SPI_D = DATA[127];

  SPI_D = DATA[128];
  SPI_D = DATA[129];
  SPI_D = DATA[130];
  SPI_D = DATA[131];
  SPI_D = DATA[132];
  SPI_D = DATA[133];
  SPI_D = DATA[134];
  SPI_D = DATA[135];

  SPI_D = DATA[136];
  SPI_D = DATA[137];
  SPI_D = DATA[138];
  SPI_D = DATA[139];
  SPI_D = DATA[140];
  SPI_D = DATA[141];
  SPI_D = DATA[142];
  SPI_D = DATA[143];

  SPI_D = DATA[144];
  SPI_D = DATA[145];
  SPI_D = DATA[146];
  SPI_D = DATA[147];
  SPI_D = DATA[148];
  SPI_D = DATA[149];
  SPI_D = DATA[150];
  SPI_D = DATA[151];

  SPI_D = DATA[152];
  SPI_D = DATA[153];
  SPI_D = DATA[154];
  SPI_D = DATA[155];
  SPI_D = DATA[156];
  SPI_D = DATA[157];
  SPI_D = DATA[158];
  SPI_D = DATA[159];

  SPI_D = DATA[160];
  SPI_D = DATA[161];
  SPI_D = DATA[162];
  SPI_D = DATA[163];
  SPI_D = DATA[164];
  SPI_D = DATA[165];
  SPI_D = DATA[166];
  SPI_D = DATA[167];

  SPI_D = DATA[168];
  SPI_D = DATA[169];
  SPI_D = DATA[170];
  SPI_D = DATA[171];
  SPI_D = DATA[172];
  SPI_D = DATA[173];
  SPI_D = DATA[174];
  SPI_D = DATA[175];

  SPI_D = DATA[176];
  SPI_D = DATA[177];
  SPI_D = DATA[178];
  SPI_D = DATA[179];
  SPI_D = DATA[180];
  SPI_D = DATA[181];
  SPI_D = DATA[182];
  SPI_D = DATA[183];

  SPI_D = DATA[184];
  SPI_D = DATA[185];
  SPI_D = DATA[186];
  SPI_D = DATA[187];
  SPI_D = DATA[188];
  SPI_D = DATA[189];
  SPI_D = DATA[190];
  SPI_D = DATA[191];

  SPI_D = DATA[192];
  SPI_D = DATA[193];
  SPI_D = DATA[194];
  SPI_D = DATA[195];
  SPI_D = DATA[196];
  SPI_D = DATA[197];
  SPI_D = DATA[198];
  SPI_D = DATA[199];

  SPI_D = DATA[200];
  SPI_D = DATA[201];
  SPI_D = DATA[202];
  SPI_D = DATA[203];
  SPI_D = DATA[204];
  SPI_D = DATA[205];
  SPI_D = DATA[206];
  SPI_D = DATA[207];

  SPI_D = DATA[208];
  SPI_D = DATA[209];
  SPI_D = DATA[210];
  SPI_D = DATA[211];
  SPI_D = DATA[212];
  SPI_D = DATA[213];
  SPI_D = DATA[214];
  SPI_D = DATA[215];

  SPI_D = DATA[216];
  SPI_D = DATA[217];
  SPI_D = DATA[218];
  SPI_D = DATA[219];
  SPI_D = DATA[220];
  SPI_D = DATA[221];
  SPI_D = DATA[222];
  SPI_D = DATA[223];

  SPI_D = DATA[224];
  SPI_D = DATA[225];
  SPI_D = DATA[226];
  SPI_D = DATA[227];
  SPI_D = DATA[228];
  SPI_D = DATA[229];
  SPI_D = DATA[230];
  SPI_D = DATA[231];

  SPI_D = DATA[232];
  SPI_D = DATA[233];
  SPI_D = DATA[234];
  SPI_D = DATA[235];
  SPI_D = DATA[236];
  SPI_D = DATA[237];
  SPI_D = DATA[238];
  SPI_D = DATA[239];

  SPI_D = DATA[240];
  SPI_D = DATA[241];
  SPI_D = DATA[242];
  SPI_D = DATA[243];
  SPI_D = DATA[244];
  SPI_D = DATA[245];
  SPI_D = DATA[246];
  SPI_D = DATA[247];

  SPI_D = DATA[248];
  SPI_D = DATA[249];
  SPI_D = DATA[250];
  SPI_D = DATA[251];
  SPI_D = DATA[252];
  SPI_D = DATA[253];
  SPI_D = DATA[254];
  SPI_D = DATA[255];

  SPI_D = DATA[256];
  SPI_D = DATA[257];
  SPI_D = DATA[258];
  SPI_D = DATA[259];
  SPI_D = DATA[260];
  SPI_D = DATA[261];
  SPI_D = DATA[262];
  SPI_D = DATA[263];

  SPI_D = DATA[264];
  SPI_D = DATA[265];
  SPI_D = DATA[266];
  SPI_D = DATA[267];
  SPI_D = DATA[268];
  SPI_D = DATA[269];
  SPI_D = DATA[270];
  SPI_D = DATA[271];

  SPI_D = DATA[272];
  SPI_D = DATA[273];
  SPI_D = DATA[274];
  SPI_D = DATA[275];
  SPI_D = DATA[276];
  SPI_D = DATA[277];
  SPI_D = DATA[278];
  SPI_D = DATA[279];

  SPI_D = DATA[280];
  SPI_D = DATA[281];
  SPI_D = DATA[282];
  SPI_D = DATA[283];
  SPI_D = DATA[284];
  SPI_D = DATA[285];
  SPI_D = DATA[286];
  SPI_D = DATA[287];

  SPI_D = DATA[288];
  SPI_D = DATA[289];
  SPI_D = DATA[290];
  SPI_D = DATA[291];
  SPI_D = DATA[292];
  SPI_D = DATA[293];
  SPI_D = DATA[294];
  SPI_D = DATA[295];

  SPI_D = DATA[296];
  SPI_D = DATA[297];
  SPI_D = DATA[298];
  SPI_D = DATA[299];
  SPI_D = DATA[300];
  SPI_D = DATA[301];
  SPI_D = DATA[302];
  SPI_D = DATA[303];

  SPI_D = DATA[304];
  SPI_D = DATA[305];
  SPI_D = DATA[306];
  SPI_D = DATA[307];
  SPI_D = DATA[308];
  SPI_D = DATA[309];
  SPI_D = DATA[310];
  SPI_D = DATA[311];

  SPI_D = DATA[312];
  SPI_D = DATA[313];
  SPI_D = DATA[314];
  SPI_D = DATA[315];
  SPI_D = DATA[316];
  SPI_D = DATA[317];
  SPI_D = DATA[318];
  SPI_D = DATA[319];

  SPI_D = DATA[320];
  SPI_D = DATA[321];
  SPI_D = DATA[322];
  SPI_D = DATA[323];
  SPI_D = DATA[324];
  SPI_D = DATA[325];
  SPI_D = DATA[326];
  SPI_D = DATA[327];

  SPI_D = DATA[328];
  SPI_D = DATA[329];
  SPI_D = DATA[330];
  SPI_D = DATA[331];
  SPI_D = DATA[332];
  SPI_D = DATA[333];
  SPI_D = DATA[334];
  SPI_D = DATA[335];

  SPI_D = DATA[336];
  SPI_D = DATA[337];
  SPI_D = DATA[338];
  SPI_D = DATA[339];
  SPI_D = DATA[340];
  SPI_D = DATA[341];
  SPI_D = DATA[342];
  SPI_D = DATA[343];

  SPI_D = DATA[344];
  SPI_D = DATA[345];
  SPI_D = DATA[346];
  SPI_D = DATA[347];
  SPI_D = DATA[348];
  SPI_D = DATA[349];
  SPI_D = DATA[350];
  SPI_D = DATA[351];

  SPI_D = DATA[352];
  SPI_D = DATA[353];
  SPI_D = DATA[354];
  SPI_D = DATA[355];
  SPI_D = DATA[356];
  SPI_D = DATA[357];
  SPI_D = DATA[358];
  SPI_D = DATA[359];

  SPI_D = DATA[360];
  SPI_D = DATA[361];
  SPI_D = DATA[362];
  SPI_D = DATA[363];
  SPI_D = DATA[364];
  SPI_D = DATA[365];
  SPI_D = DATA[366];
  SPI_D = DATA[367];

  SPI_D = DATA[368];
  SPI_D = DATA[369];
  SPI_D = DATA[370];
  SPI_D = DATA[371];
  SPI_D = DATA[372];
  SPI_D = DATA[373];
  SPI_D = DATA[374];
  SPI_D = DATA[375];

  SPI_D = DATA[376];
  SPI_D = DATA[377];
  SPI_D = DATA[378];
  SPI_D = DATA[379];
  SPI_D = DATA[380];
  SPI_D = DATA[381];
  SPI_D = DATA[382];
  SPI_D = DATA[383];

  SPI_D = DATA[384];
  SPI_D = DATA[385];
  SPI_D = DATA[386];
  SPI_D = DATA[387];
  SPI_D = DATA[388];
  SPI_D = DATA[389];
  SPI_D = DATA[390];
  SPI_D = DATA[391];

  SPI_D = DATA[392];
  SPI_D = DATA[393];
  SPI_D = DATA[394];
  SPI_D = DATA[395];
  SPI_D = DATA[396];
  SPI_D = DATA[397];
  SPI_D = DATA[398];
  SPI_D = DATA[399];

  SPI_D = DATA[400];
  SPI_D = DATA[401];
  SPI_D = DATA[402];
  SPI_D = DATA[403];
  SPI_D = DATA[404];
  SPI_D = DATA[405];
  SPI_D = DATA[406];
  SPI_D = DATA[407];

  SPI_D = DATA[408];
  SPI_D = DATA[409];
  SPI_D = DATA[410];
  SPI_D = DATA[411];
  SPI_D = DATA[412];
  SPI_D = DATA[413];
  SPI_D = DATA[414];
  SPI_D = DATA[415];

  SPI_D = DATA[416];
  SPI_D = DATA[417];
  SPI_D = DATA[418];
  SPI_D = DATA[419];
  SPI_D = DATA[420];
  SPI_D = DATA[421];
  SPI_D = DATA[422];
  SPI_D = DATA[423];

  SPI_D = DATA[424];
  SPI_D = DATA[425];
  SPI_D = DATA[426];
  SPI_D = DATA[427];
  SPI_D = DATA[428];
  SPI_D = DATA[429];
  SPI_D = DATA[430];
  SPI_D = DATA[431];

  SPI_D = DATA[432];
  SPI_D = DATA[433];
  SPI_D = DATA[434];
  SPI_D = DATA[435];
  SPI_D = DATA[436];
  SPI_D = DATA[437];
  SPI_D = DATA[438];
  SPI_D = DATA[439];

  SPI_D = DATA[440];
  SPI_D = DATA[441];
  SPI_D = DATA[442];
  SPI_D = DATA[443];
  SPI_D = DATA[444];
  SPI_D = DATA[445];
  SPI_D = DATA[446];
  SPI_D = DATA[447];

  SPI_D = DATA[448];
  SPI_D = DATA[449];
  SPI_D = DATA[450];
  SPI_D = DATA[451];
  SPI_D = DATA[452];
  SPI_D = DATA[453];
  SPI_D = DATA[454];
  SPI_D = DATA[455];

  SPI_D = DATA[456];
  SPI_D = DATA[457];
  SPI_D = DATA[458];
  SPI_D = DATA[459];
  SPI_D = DATA[460];
  SPI_D = DATA[461];
  SPI_D = DATA[462];
  SPI_D = DATA[463];

  SPI_D = DATA[464];
  SPI_D = DATA[465];
  SPI_D = DATA[466];
  SPI_D = DATA[467];
  SPI_D = DATA[468];
  SPI_D = DATA[469];
  SPI_D = DATA[470];
  SPI_D = DATA[471];

  SPI_D = DATA[472];
  SPI_D = DATA[473];
  SPI_D = DATA[474];
  SPI_D = DATA[475];
  SPI_D = DATA[476];
  SPI_D = DATA[477];
  SPI_D = DATA[478];
  SPI_D = DATA[479];

  SPI_D = DATA[480];
  SPI_D = DATA[481];
  SPI_D = DATA[482];
  SPI_D = DATA[483];
  SPI_D = DATA[484];
  SPI_D = DATA[485];
  SPI_D = DATA[486];
  SPI_D = DATA[487];

  SPI_D = DATA[488];
  SPI_D = DATA[489];
  SPI_D = DATA[490];
  SPI_D = DATA[491];
  SPI_D = DATA[492];
  SPI_D = DATA[493];
  SPI_D = DATA[494];
  SPI_D = DATA[495];

  SPI_D = DATA[496];
  SPI_D = DATA[497];
  SPI_D = DATA[498];
  SPI_D = DATA[499];
  SPI_D = DATA[500];
  SPI_D = DATA[501];
  SPI_D = DATA[502];
  SPI_D = DATA[503];

  SPI_D = DATA[504];
  SPI_D = DATA[505];
  SPI_D = DATA[506];
  SPI_D = DATA[507];
  SPI_D = DATA[508];
  SPI_D = DATA[509];
  SPI_D = DATA[510];
  SPI_D = DATA[511];

  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}