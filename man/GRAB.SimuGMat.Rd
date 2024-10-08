% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/GRAB_Simu.R
\name{GRAB.SimuGMat}
\alias{GRAB.SimuGMat}
\title{Simulate an R matrix of genotype data}
\usage{
GRAB.SimuGMat(
  nSub,
  nFam,
  FamMode,
  nSNP,
  MaxMAF = 0.5,
  MinMAF = 0.05,
  MAF = NULL
)
}
\arguments{
\item{nSub}{the number of unrelated subjects in simulations, if \code{nSub = 0}, then all subjects are related to at least one of the others.}

\item{nFam}{the number of families in simulation, if \code{nFam = 0}, then all subjects are unrelated to each other.}

\item{FamMode}{\code{"4-members"}, \code{"10-members"}, or \code{"20-members"}. Check \code{Details} section for more details.}

\item{nSNP}{number of markers to simulate}

\item{MaxMAF}{a numeric value \emph{(default=0.5)}, haplotype is simulated with allele frequency <= this value.}

\item{MinMAF}{a numeric value \emph{(default=0.05)}, haplotype is simulated with allele frequency >= this value.}

\item{MAF}{a numeric vector with a length of \emph{nSNP}. If this argument is given, then arguments of \emph{MaxMAF} and \emph{MinMAF} would be ignored.}
}
\value{
an R list including genotype matrix and marker information
\itemize{
\item \code{GenoMat} a numeric matrix of genotype: each row is for one subject and each column is for one SNP
\item \code{markerInfo} a data frame with the following 2 columns: SNP ID and minor allele frequency
}
}
\description{
\code{GRAB} package provides functions to simulate genotype data. We support simulations based on unrelated subjects and related subjects.
}
\details{
Currently, function \code{GRAB.SimuGMat} supports both unrelated and related subjects.
Genotype data is simulated following Hardy-Weinberg Equilibrium with allele frequency ~ \code{runif(MinMAF, MaxMAF)}.
\subsection{If \code{FamMode = "4-members"}}{

Total number of subjects is \code{nSub + 4 * nFam}. Each family includes 4 members with the family structure as below: 1+2->3+4.
}

\subsection{If \code{FamMode = "10-members"}}{

Total number of subjects is \code{nSub + 10 * nFam}. Each family includes 10 members with the family structure as below: 1+2->5+6, 3+5->7+8, 4+6->9+10.
}

\subsection{If \code{FamMode = "20-members"}}{

Total number of subjects is \code{nSub + 20 * nFam}. Each family includes 20 members with the family structure as below: 1+2->9+10, 3+9->11+12, 4+10->13+14, 5+11->15+16, 6+12->17, 7+13->18, 8+14->19+20.
}
}
\examples{
nSub = 100
nFam = 10
FamMode = "10-members"
nSNP = 10000
OutList = GRAB.SimuGMat(nSub, nFam, FamMode, nSNP)      
GenoMat = OutList$GenoMat
markerInfo = OutList$markerInfo
GenoMat[1:10,1:10]
head(markerInfo)

## The following is to calculate GRM
MAF = apply(GenoMat, 2, mean)/2
GenoMatSD = t((t(GenoMat) - 2*MAF)/sqrt(2*MAF*(1-MAF)))
GRM = GenoMatSD \%*\% t(GenoMatSD) / ncol(GenoMat)
GRM1 = GRM[1:10, 1:10];
GRM2 = GRM[100+1:10, 100+1:10];
GRM1
GRM2
}
\seealso{
\code{\link{GRAB.makePlink}} can make \code{PLINK} files using the genotype matrix.
}
