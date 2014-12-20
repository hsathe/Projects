import java.io.File;
import com.amazonaws.AmazonClientException;
import com.amazonaws.auth.PropertiesCredentials;
import com.amazonaws.services.s3.transfer.TransferManager;
import com.amazonaws.services.s3.transfer.Upload;

public class HighLevel_Java_UploadFile 
{

	
	public static void main(String[] args) throws Exception
	{
		String existingBucketName = "msecured";
		String keyName             = "aws-7mar";
		String filePath            = "/home/harshad/harsh.txt";
		TransferManager tm = new TransferManager(new PropertiesCredentials(
		   HighLevel_Java_UploadFile.class.getResourceAsStream(
		                        "AwsCredentials.properties")));
		// TransferManager processes all transfers asynchronously,
		// so this call will return immediately.
		Upload upload = tm.upload(
		   existingBucketName, keyName, new File(filePath));
		try {
		  // Or you can block and wait for the upload to finish
		  upload.waitForCompletion();
		} catch (AmazonClientException amazonClientException) {
		  System.out.println("Unable to upload file, upload was aborted.");
		  amazonClientException.printStackTrace();
		}


	}

}
