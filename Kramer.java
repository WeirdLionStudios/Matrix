/**
 * Kramer method
 * 
 * @author Venio
 */

import java.util.Random;
import java.util.Scanner;

public class Kramer {
	
	static final double INIT_MAX=10;
	
	static int dim;
	
	static double[][] coeff, b_coeff;
	static double[] ans;
	
	static double[] res;
	
	static double det, b_det;
	
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		System.out.println("Inserire la dimensione della matrice");
		dim=in.nextInt();
		
		//Initialize with random values
		coeff=new double[dim][dim];
		b_coeff=new double[dim][dim];
		ans=new double[dim];
		res=new double[dim];
		
		Random rand=new Random();
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++)
				coeff[i][j]=(double)(rand.nextInt()%INIT_MAX);
			ans[i]=(double)(rand.nextInt()%INIT_MAX);
		}
		
		//Print matrices
		printMatrix("Coefficient matrix", coeff);
		System.out.println("\nAnswer matrix");
		for(int i=0;i<dim;i++)
			System.out.println(ans[i]);
		
		//Kramer method
		det=determinant(coeff, dim);
		
		for(int i=0;i<dim;i++){
			b_coeff=setMatrix(coeff);
			for(int j=0;j<dim;j++){
				b_coeff[j][i]=ans[j];
			}
			b_det=determinant(b_coeff, dim);
			res[i]=b_det/det;
		}
		
		//Show results
		for(int i=0;i<dim;i++)
			System.out.println("x_"+i+": "+res[i]);
	}
	
	//Get determinant using laplacian expansion
	static double determinant(double[][] a, int d){
		double det=0;
		if(d<2){
			System.err.println("Inconsistent matrix size");
			System.exit(1);
			return 0;
		}
		if(d==2)
			return a[0][0]*a[1][1]-a[1][0]*a[0][1];
		for(int i=0;i<d;i++)
			det+=a[0][i]*determinant(getSub(a, i, 0), d-1)*Math.pow(-1,i);
			
		return det;
	}
	
	//Get submatrix by eliminating row and column
	static double[][] getSub(double[][] a, int col, int row){
		int d=a.length;
		double[][] n=new double[d-1][d-1];
		
		int r=0, c=0;
		for(int i=0;i<d;i++){
			c=0;
			if(i==row)
				continue;
			for(int j=0;j<d;j++){
				if(j!=col)
					n[r][c++]=a[i][j];
			}
			r++;
		}
		return n;
	}
	
	//Copy the contents of a matrix into another
	static double[][] setMatrix(double[][] a){
		double[][] b=new double[a.length][a[0].length];
		for(int i=0;i<a.length;i++)
			for(int j=0;j<a[0].length;j++)
				b[i][j]=a[i][j];
		return b;
	}
	
	//Print the contents of a matrix, with a header to make things nice
	static void printMatrix(String header, double[][] matrix){
		System.out.println(header);
		for(int i=0;i<matrix.length;i++){
			for(int j=0;j<matrix[i].length;j++)
				System.out.print(matrix[i][j]+" ");
			System.out.print("\n");
		}
		System.out.print("\n");
	}
}
