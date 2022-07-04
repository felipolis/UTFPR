/*
  Warnings:

  - You are about to drop the column `lastName` on the `User` table. All the data in the column will be lost.
  - You are about to drop the column `name` on the `User` table. All the data in the column will be lost.
  - You are about to drop the column `password` on the `User` table. All the data in the column will be lost.
  - Added the required column `nome` to the `User` table without a default value. This is not possible if the table is not empty.
  - Added the required column `senha` to the `User` table without a default value. This is not possible if the table is not empty.
  - Added the required column `sobrenome` to the `User` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "User" DROP COLUMN "lastName",
DROP COLUMN "name",
DROP COLUMN "password",
ADD COLUMN     "nome" TEXT NOT NULL,
ADD COLUMN     "senha" TEXT NOT NULL,
ADD COLUMN     "sobrenome" TEXT NOT NULL;
