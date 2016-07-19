import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class InvFileTrim {
	public static void main(String[] argv) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(argv[1]));
			BufferedWriter bw = new BufferedWriter(new FileWriter(argv[2]));
			String line, output;
			String[] term, list, post;
			int docid, tf;
			while ((line = br.readLine()) != null) {
				term = line.split(":")[0].split(" ");
				list = line.split(":")[1].split(",");
				if (term[0].charAt(0) > 'z' || list.length > Integer.parseInt(argv[0])) {
					continue;
				}
				output = term[0] + " " + term[1] + ":";
				for (String str : list) {
					post = str.split(" ");
					docid = Integer.parseInt(post[0]);
					tf = Integer.parseInt(post[1]);
					output += docid + " " + tf + ",";
				}
				output += "\r\n";
				bw.write(output);
			}
			br.close();
			bw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}