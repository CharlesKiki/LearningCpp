int main()
{
    //Step1, input several integers and write them into the file
    int data;
    char fileName[20] = "data.txt";
    ofstream fout(fileName);//open the file
    while(cin>>data)//input an integer from the keyboard
    {
        if(data==0)//if the input data is 0, then exit the loop
        {
            break;
        }
        fout<<data<<endl;//write the input data into the file
    }
    fout.close();//close the file

    //Setp2, read the integers from the file and output their summary
    ifstream fin(fileName);//open the file
    int sum = 0;
    while(fin>>data)//read a data from the file
    {
        sum = sum + data;//add the data to the summary variable
    }
    fin.close();//close the file

    //Step3, output the summary
    cout<<"The summary is "<<sum<<endl;

    return 0;
}
